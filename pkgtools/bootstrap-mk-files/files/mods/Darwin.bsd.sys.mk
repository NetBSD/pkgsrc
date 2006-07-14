#	$NetBSD: Darwin.bsd.sys.mk,v 1.1.1.1 2006/07/14 23:13:01 jlam Exp $

#OBJCOPY?=	objcopy
STRIP?=		strip
CONFIG?=	config
RPCGEN?=	rpcgen
MKLOCALE?=	mklocale

.SUFFIXES:	.m .o .ln .lo

# Objective C
# (Defined here rather than in <sys.mk> because `.m' is not just
#  used for Objective C source)
.m:
	${LINK.m} -o ${.TARGET} ${.IMPSRC} ${LDLIBS}
.m.o:
	${COMPILE.m} ${.IMPSRC}

.if defined(PARALLEL) || defined(LPREFIX)
LPREFIX?=yy
LFLAGS+=-P${LPREFIX}
# Lex
.l:
	${LEX.l} -o${.TARGET:R}.${LPREFIX}.c ${.IMPSRC}
	${LINK.c} -o ${.TARGET} ${.TARGET:R}.${LPREFIX}.c ${LDLIBS} -ll
	rm -f ${.TARGET:R}.${LPREFIX}.c
.l.c:
	${LEX.l} -o${.TARGET} ${.IMPSRC}
.l.o:
	${LEX.l} -o${.TARGET:R}.${LPREFIX}.c ${.IMPSRC}
	${COMPILE.c} -o ${.TARGET} ${.TARGET:R}.${LPREFIX}.c 
	rm -f ${.TARGET:R}.${LPREFIX}.c
.endif

# Yacc
.if defined(YHEADER) || defined(YPREFIX)
.if defined(YPREFIX)
YFLAGS+=-p${YPREFIX}
.endif
.if defined(YHEADER)
YFLAGS+=-d
.endif
.y:
	${YACC.y} -b ${.TARGET:R} ${.IMPSRC}
	${LINK.c} -o ${.TARGET} ${.TARGET:R}.tab.c ${LDLIBS}
	rm -f ${.TARGET:R}.tab.c ${.TARGET:R}.tab.h
.y.h: ${.TARGET:R}.c
.y.c:
	${YACC.y} -o ${.TARGET} ${.IMPSRC}
.y.o:
	${YACC.y} -b ${.TARGET:R} ${.IMPSRC}
	${COMPILE.c} -o ${.TARGET} ${.TARGET:R}.tab.c
	rm -f ${.TARGET:R}.tab.c ${TARGET:R}.tab.h
.elif defined(PARALLEL)
.y:
	${YACC.y} -b ${.TARGET:R} ${.IMPSRC}
	${LINK.c} -o ${.TARGET} ${.TARGET:R}.tab.c ${LDLIBS}
	rm -f ${.TARGET:R}.tab.c
.y.c:
	${YACC.y} -o ${.TARGET} ${.IMPSRC}
.y.o:
	${YACC.y} -b ${.TARGET:R} ${.IMPSRC}
	${COMPILE.c} -o ${.TARGET} ${.TARGET:R}.tab.c
	rm -f ${.TARGET:R}.tab.c
.endif
