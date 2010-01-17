#	$NetBSD: Makefile,v 1.2 2010/01/17 01:41:34 dholland Exp $

TOP=../..
include $(TOP)/mk/setup.mk

PROG=prt3270
SRCS=prt3270.c ../../api/asc_ebc.c ../../api/ebc_disp.c ../../api/astosc.c

GENFILES=kbd.out astosc.out

CFLAGS+=-I../../api
CFLAGS+=-I.
CFLAGS+=-DHOST_TOOL

# should be hostprog.mk for crosscompiling (FUTURE)
include $(TOP)/mk/prog.mk

MKHITS=../mkhits/mkhits
MKASTOSC=../mkastosc/mkastosc

kbd.out astosc.out: ../../ctlr/hostctlr.h ../../ctlr/$(KBD)

kbd.out: $(MKHITS) ../../ctlr/function.c
	$(CC) $(CFLAGS) -E ../../ctlr/function.c > kbd.tmp
	$(MKHITS) ../../ctlr/hostctlr.h kbd.tmp  < ../../ctlr/$(KBD) > kbd.tmp2
	rm -f kbd.tmp
	mv -f kbd.tmp2 kbd.out

astosc.out: ${MKASTOSC} ../../ctlr/function.h
	${MKASTOSC} ../../ctlr/hostctlr.h ../../ctlr/function.h \
	    < ../../ctlr/${KBD} > astosc.tmp
	mv -f astosc.tmp astosc.out

clean: cleanhere
cleanhere:
	rm -f kbd.tmp kbd.tmp2 astosc.tmp

# depend ought to pick these up, but just in case
astosc.o:	astosc.out
prt3270.o:	kbd.out
