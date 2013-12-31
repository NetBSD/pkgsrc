#	$NetBSD: bsd.prog.mk,v 1.2 2013/12/31 19:10:20 dholland Exp $
#	@(#)bsd.prog.mk	8.2 (Berkeley) 4/2/94

.if !target(__initialized__)
__initialized__:
.if exists(${.CURDIR}/../Makefile.inc)
.include "${.CURDIR}/../Makefile.inc"
.endif
.include <bsd.own.mk>
.include <bsd.obj.mk>
.include <bsd.depall.mk>
.MAIN:		all
.endif

.PHONY:		cleanprog proginstall scriptsinstall
realinstall:	proginstall scriptsinstall
clean cleandir: cleanprog

CFLAGS+=	${COPTS}

# ELF platforms depend on crtbegin.o and crtend.o
.if ${OBJECT_FMT} == "ELF" && ${MACHINE:Mirix} != ""
LIBCRTBEGIN?=	${DESTDIR}/usr/lib/crtbegin.o
LIBCRTEND?=	${DESTDIR}/usr/lib/crtend.o
.else
LIBCRTBEGIN?=
LIBCRTEND?=
.endif

# here is where you can define what LIB* are
.-include <libnames.mk>

.if defined(SHAREDSTRINGS)
CLEANFILES+=strings
.c.o:
	${CC} -E ${CFLAGS} ${.IMPSRC} | xstr -c -
	@${CC} ${CFLAGS} -c x.c -o ${.TARGET}
	@rm -f x.c

.cc.o:
	${CXX} -E ${CXXFLAGS} ${.IMPSRC} | xstr -c -
	@mv -f x.c x.cc
	@${CXX} ${CXXFLAGS} -c x.cc -o ${.TARGET}
	@rm -f x.cc

.C.o:
	${CXX} -E ${CXXFLAGS} ${.IMPSRC} | xstr -c -
	@mv -f x.c x.C
	@${CXX} ${CXXFLAGS} -c x.C -o ${.TARGET}
	@rm -f x.C
.endif


.if defined(PROG)
PROGS?=		${PROG}
.if defined(PROGNAME)
PROGNAME.${PROG}?=${PROGNAME}
.endif
.if defined(SRCS)
SRCS.${PROG}?=	${SRCS}
.endif
.if defined(DPSRCS)
DPSRCS.${PROG}?=${DPSRCS}
.endif
.endif

.if defined(PROGS)
.for P in $(PROGS)
SRCS.${P}?=	${P}.c

DPSRCS.${P}+=	${SRCS.${P}:M*.l:.l=.c} ${SRCS.${P}:M*.y:.y=.c}
CLEANFILES+=	${DPSRCS.${P}}
.if defined(YHEADER)
CLEANFILES+=	${SRCS.${P}:M*.y:.y=.h}
.endif

.if !empty(SRCS.${P}:N*.h:N*.sh:N*.fth)
OBJS.${P}+=	${SRCS.${P}:N*.h:N*.sh:N*.fth:R:S/$/.o/g}
LOBJS.${P}+=	${LSRCS.${P}:.c=.ln} ${SRCS.${P}:M*.c:.c=.ln}
.endif

.if defined(OBJS.${P}) && !empty(OBJS.${P})
.NOPATH: ${OBJS.${P}}
.if defined(DESTDIR)

${P}: ${LIBCRT0} ${DPSRCS.${P}} ${OBJS.${P}} ${LIBC} ${LIBCRTBEGIN} ${LIBCRTEND} ${DPADD} ${DPADD.${P}}
.if !commands(${PROG.${P}})
	${CC} ${LDFLAGS} ${LDFLAGS.${P}} ${LDSTATIC} ${LDSTATIC.${P}} -o ${.TARGET} -nostdlib -Wl,-rpath-link,${DESTDIR}/usr/lib ${LIBCRT0} ${LIBCRTBEGIN} ${OBJS.${P}} ${LDADD.${P}} ${LDADD} -L${DESTDIR}/usr/lib -lgcc -lc -lgcc ${LIBCRTEND}
.endif

.else

${P}: ${LIBCRT0} ${DPSRCS.${P}} ${OBJS.${P}} ${LIBC} ${LIBCRTBEGIN} ${LIBCRTEND} ${DPADD} ${DPADD.${P}}
.if !commands(${PROG})
	${CC} ${LDFLAGS} ${LDFLAGS.${P}} ${LDSTATIC} ${LDSTATIC.${P}} -o ${.TARGET} ${OBJS.${P}} ${LDADD.${P}} ${LDADD}
.endif

.endif	# defined(DESTDIR)
.endif	# defined(OBJS) && !empty(OBJS)

.endfor	# P in PROGS

.if !defined(MAN)
.for P in ${PROGS}
MAN+=	${P}.1
.endfor
.endif	# !defined(MAN)
.endif	# defined(PROGS)

realall: ${PROGS} ${SCRIPTS}

cleanprog:
	rm -f a.out [Ee]rrs mklog core *.core \
	    ${PROGS} ${OBJS} ${LOBJS} ${CLEANFILES}

.if defined(SRCS) && !target(afterdepend)
afterdepend: .depend
	@(TMP=/tmp/_depend$$$$; \
	    sed -e 's/^\([^\.]*\).o[ ]*:/\1.o \1.ln:/' \
	      < .depend > $$TMP; \
	    mv $$TMP .depend)
.endif

.if defined(PROGS) && !target(proginstall)

__proginstall: .USE
	${INSTALL} ${RENAME} ${PRESERVE} ${COPY} ${STRIPFLAG} ${INSTPRIV} \
	    -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${.ALLSRC} ${.TARGET}

.for P in ${PROGS}
PROGNAME.${P}?=${P}

proginstall:: ${DESTDIR}${BINDIR}/${PROGNAME.${P}}
.PRECIOUS: ${DESTDIR}${BINDIR}/${PROGNAME.${P}}
.if !defined(UPDATE)
.PHONY: ${DESTDIR}${BINDIR}/${PROGNAME.${P}}
.endif

.if !defined(BUILD) && !make(all) && !make(${P})
${DESTDIR}${BINDIR}/${PROGNAME.${P}}: .MADE
.endif
${DESTDIR}${BINDIR}/${PROGNAME.${P}}: ${P} __proginstall
.endfor
.endif

.if !target(proginstall)
proginstall::
.endif

.if defined(SCRIPTS) && !target(scriptsinstall)
SCRIPTSDIR?=${BINDIR}
SCRIPTSOWN?=${BINOWN}
SCRIPTSGRP?=${BINGRP}
SCRIPTSMODE?=${BINMODE}

scriptsinstall:: ${SCRIPTS:@S@${DESTDIR}${SCRIPTSDIR_${S}:U${SCRIPTSDIR}}/${SCRIPTSNAME_${S}:U${SCRIPTSNAME:U${S:T:R}}}@}
.PRECIOUS: ${SCRIPTS:@S@${DESTDIR}${SCRIPTSDIR_${S}:U${SCRIPTSDIR}}/${SCRIPTSNAME_${S}:U${SCRIPTSNAME:U${S:T:R}}}@}
.if !defined(UPDATE)
.PHONY: ${SCRIPTS:@S@${DESTDIR}${SCRIPTSDIR_${S}:U${SCRIPTSDIR}}/${SCRIPTSNAME_${S}:U${SCRIPTSNAME:U${S:T:R}}}@}
.endif

__scriptinstall: .USE
	${INSTALL} ${RENAME} ${PRESERVE} ${COPY} ${INSTPRIV} \
	    -o ${SCRIPTSOWN_${.ALLSRC:T}:U${SCRIPTSOWN}} \
	    -g ${SCRIPTSGRP_${.ALLSRC:T}:U${SCRIPTSGRP}} \
	    -m ${SCRIPTSMODE_${.ALLSRC:T}:U${SCRIPTSMODE}} \
	    ${.ALLSRC} ${.TARGET}

.for S in ${SCRIPTS:O:u}
.if !defined(BUILD) && !make(all) && !make(${S})
${DESTDIR}${SCRIPTSDIR_${S}:U${SCRIPTSDIR}}/${SCRIPTSNAME_${S}:U${SCRIPTSNAME:U${S:T:R}}}: .MADE
.endif
${DESTDIR}${SCRIPTSDIR_${S}:U${SCRIPTSDIR}}/${SCRIPTSNAME_${S}:U${SCRIPTSNAME:U${S:T:R}}}: ${S} __scriptinstall
.endfor
.endif

.if !target(scriptsinstall)
scriptsinstall::
.endif

lint: ${LOBJS}
.if defined(LOBJS) && !empty(LOBJS)
	${LINT} ${LINTFLAGS} ${LDFLAGS:M-L*} ${LOBJS} ${LDADD}
.endif

.include <bsd.man.mk>
.include <bsd.nls.mk>
.include <bsd.files.mk>
.include <bsd.inc.mk>
.include <bsd.links.mk>
.include <bsd.dep.mk>
.include <bsd.sys.mk>

# Make sure all of the standard targets are defined, even if they do nothing.
regress:
