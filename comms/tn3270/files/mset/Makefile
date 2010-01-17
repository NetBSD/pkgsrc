#	$NetBSD: Makefile,v 1.2 2010/01/17 01:41:34 dholland Exp $

TOP=..
include $(TOP)/mk/setup.mk

MAN=	mset.1 map3270.5

CFLAGS+=-I.

PROG=mset
SRCS=../api/astosc.c ../ascii/map3270.c ../ascii/mset.c
GENFILES=astosc.out

include $(TOP)/mk/prog.mk

MKASTOSC=../tools/mkastosc/mkastosc

astosc.out: ${MKASTOSC} ../ctlr/hostctlr.h ../ctlr/function.h ../ctlr/${KBD}
	${MKASTOSC} ../ctlr/hostctlr.h ../ctlr/function.h \
	    < ../ctlr/${KBD} > astosc.tmp
	mv -f astosc.tmp ${.TARGET}

clean: cleanhere
cleanhere:
	rm -f astosc.tmp

# depend should catch this, but just in case
astosc.o:	astosc.out
