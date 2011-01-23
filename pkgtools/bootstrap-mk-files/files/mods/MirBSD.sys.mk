#	$NetBSD: MirBSD.sys.mk,v 1.1 2011/01/23 19:07:26 agc Exp $
#	$MirOS: src/share/mk/sys.mk,v 1.103 2007/04/28 00:12:46 tg Exp $
#	@(#)sys.mk    5.11 (Berkeley) 3/13/91

unix?=		We run MirOS BSD.

.SUFFIXES:	.out .a .ln .o .s .S .c .m .cc .cxx .cpp .C .F .f .r .y .l .cl .p .i .h .sh .m4
.LIBS:		.a

AR?=		ar
ARFLAGS?=	rl
RANLIB?=	ranlib
NM?=		nm
LORDER?=	lorder

AS?=		as
CC?=		mgcc
HOST_CC?=	mgcc
CPP?=		${CC} -E

CPPFLAGS?=

AFLAGS?=	${DEBUG}
COMPILE.s?=	${CC} -D_ASM_SOURCE ${AFLAGS} -c
LINK.s?=	${CC} -D_ASM_SOURCE ${AFLAGS} ${LDFLAGS}
COMPILE.S?=	${CC} -D_ASM_SOURCE ${AFLAGS} ${CPPFLAGS} -c -traditional-cpp
LINK.S?=	${CC} -D_ASM_SOURCE ${AFLAGS} ${CPPFLAGS} ${LDFLAGS}

DBG?=		-O2 -pipe
CFLAGS?=	${DBG} ${DEBUG}
COMPILE.c?=	${CC} ${CFLAGS:M*} ${CPPFLAGS} -c
LINK.c?=	${CC} ${CFLAGS:M*} ${CPPFLAGS} ${LDFLAGS}

CXX?=		c++
CXXFLAGS?=	${CFLAGS}
COMPILE.cc?=	${CXX} ${CXXFLAGS:M*} ${CPPFLAGS} -c
LINK.cc?=	${CXX} ${CXXFLAGS:M*} ${CPPFLAGS} ${LDFLAGS}

OBJC?=		${CC}
OBJCFLAGS?=	${CFLAGS}
COMPILE.m?=	${CC} ${OBJCFLAGS:M*} ${CPPFLAGS} -c
LINK.m?=	${CC} ${OBJCFLAGS:M*} ${CPPFLAGS} ${LDFLAGS}

FC?=		f77
FFLAGS?=	-O
RFLAGS?=
COMPILE.f?=	${FC} ${FFLAGS} -c
LINK.f?=	${FC} ${FFLAGS} ${LDFLAGS}
COMPILE.F?=	${FC} ${FFLAGS} ${CPPFLAGS} -c
LINK.F?=	${FC} ${FFLAGS} ${CPPFLAGS} ${LDFLAGS}
COMPILE.r?=	${FC} ${FFLAGS} ${RFLAGS} -c
LINK.r?=	${FC} ${FFLAGS} ${RFLAGS} ${LDFLAGS}

LEX?=		lex
LFLAGS?=
LEX.l?=		${LEX} ${LFLAGS}

LD?=		ld
LDFLAGS+=	${DEBUG}

LINT?=		lint
LINTFLAGS?=	-chapbxzF

MAKE?=		make

PC?=		pc
PFLAGS?=
COMPILE.p?=	${PC} ${PFLAGS} ${CPPFLAGS} -c
LINK.p?=	${PC} ${PFLAGS} ${CPPFLAGS} ${LDFLAGS}

SHELL?=		/bin/mksh

SIZE?=		size

TSORT?= 	tsort -q

YACC?=		yacc
YFLAGS?=
YACC.y?=	${YACC} ${YFLAGS}

INSTALL?=	install

CTAGS?=		/usr/bin/ctags

# C
.c:
	${LINK.c} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.c.o:
	${COMPILE.c} ${CFLAGS_${.TARGET}:M*} ${.IMPSRC}
.c.i:
	${COMPILE.c} ${CFLAGS_${.TARGET}:M*} -o ${.TARGET} -E ${.IMPSRC}
.c.a:
	${COMPILE.c} ${CFLAGS_${.TARGET:S/.a$/.o/}:M*} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o
.c.ln:
	${LINT} ${LINTFLAGS} ${CFLAGS:M-[IDU]*} ${CPPFLAGS:M-[IDU]*} \
	    -i ${.IMPSRC}

# Objective-C
.m:
	${LINK.m} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.m.o:
	${COMPILE.m} ${OBJCFLAGS_${.TARGET}:M*} ${.IMPSRC}
.m.i:
	${COMPILE.m} ${OBJCFLAGS_${.TARGET}:M*} -o ${.TARGET} -E ${.IMPSRC}
.m.a:
	${COMPILE.m} ${OBJCFLAGS_${.TARGET:S/.a$/.o/}:M*} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o
.m.ln:
	${LINT} ${LINTFLAGS} ${OBJCFLAGS:M-[IDU]*} ${CPPFLAGS:M-[IDU]*} \
	    -i ${.IMPSRC}

# C++
.cc .cxx .cpp .C:
	${LINK.cc} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.cc.o .cxx.o .cpp.o .C.o:
	${COMPILE.cc} ${CXXFLAGS_${.TARGET}:M*} ${.IMPSRC}
.cc.i .cxx.i .cpp.i .C.i:
	${COMPILE.cc} ${CXXFLAGS_${.TARGET}:M*} -o ${.TARGET} -E ${.IMPSRC}
.cc.a .cxx.a .cpp.a .C.a:
	${COMPILE.cc} ${CXXFLAGS_${.TARGET:S/.a$/.o/}:M*} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

# Fortran/Ratfor
.f:
	${LINK.f} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.f.o:
	${COMPILE.f} ${.IMPSRC}
.f.a:
	${COMPILE.f} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.F:
	${LINK.F} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.F.o:
	${COMPILE.F} ${.IMPSRC}
.F.a:
	${COMPILE.F} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.r:
	${LINK.r} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.r.o:
	${COMPILE.r} ${.IMPSRC}
.r.a:
	${COMPILE.r} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

# Pascal
.p:
	${LINK.p} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.p.o:
	${COMPILE.p} ${.IMPSRC}
.p.a:
	${COMPILE.p} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

# Assembly
.s:
	${LINK.s} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.s.o:
	${COMPILE.s} ${AFLAGS_${.TARGET}:M*} ${.IMPSRC}
.s.a:
	${COMPILE.s} ${AFLAGS_${.TARGET:S/.a$/.o/}:M*} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

.S:
	${LINK.S} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.S.o:
	${COMPILE.S} ${AFLAGS_${.TARGET}:M*} ${.IMPSRC}
.S.i:
	${COMPILE.S} ${AFLAGS_${.TARGET}:M*} -o ${.TARGET} -E ${.IMPSRC}
.S.a:
	${COMPILE.S} ${AFLAGS_${.TARGET:S/.a$/.o/}:M*} ${.IMPSRC}
	${AR} ${ARFLAGS} $@ $*.o
	rm -f $*.o

# Lex
.l:
	${LEX.l} -o${.TARGET:R}.yy.c ${.IMPSRC}
	${LINK.c} -o ${.TARGET} ${.TARGET:R}.yy.c ${LDLIBS} -ll
	rm -f ${.TARGET:R}.yy.c
.l.c:
	${LEX.l} -o${.TARGET} ${.IMPSRC}
.l.o:
	${LEX.l} -o${.TARGET:R}.yy.c ${.IMPSRC}
	${COMPILE.c} ${CFLAGS_${.TARGET}:M*} -o ${.TARGET} ${.TARGET:R}.yy.c
	rm -f ${.TARGET:R}.yy.c

# Yacc
.y:
	${YACC.y} -o ${.TARGET:R}.tab.c ${.IMPSRC}
	${LINK.c} -o ${.TARGET} ${.TARGET:R}.tab.c ${LDLIBS}
	rm -f ${.TARGET:R}.tab.c
.y.c:
	${YACC.y} -o ${.TARGET} ${.IMPSRC}
.y.o:
	${YACC.y} -o ${.TARGET:R}.tab.c ${.IMPSRC}
	${COMPILE.c} ${CFLAGS_${.TARGET}:M*} -o ${.TARGET} ${.TARGET:R}.tab.c
	rm -f ${.TARGET:R}.tab.c

# Shell
.sh:
	rm -f ${.TARGET}
	cp ${.IMPSRC} ${.TARGET}
