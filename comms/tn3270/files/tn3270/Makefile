#	$NetBSD: Makefile,v 1.2 2010/01/17 01:41:34 dholland Exp $

TOP=..
include $(TOP)/mk/setup.mk

#.if (defined(HAVE_GCC) && ${HAVE_GCC} == 4) || defined(HAVE_PCC)
#.for f in api commands system telnet terminal termout tn3270 utilities
#COPTS.${f}.c+=  -Wno-pointer-sign
#.endfor
#.endif

CFLAGS+=-I.

PROG=tn3270
SRCS=\
	../api/api_bsd.c \
	../api/api_exch.c \
	../api/apilib.c \
	../api/asc_ebc.c \
	../api/astosc.c \
	../api/dctype.c \
	../api/disp_asc.c \
	../api/ebc_disp.c \
	../ascii/map3270.c \
	../ascii/termin.c \
	../ctlr/api.c \
	../ctlr/function.c \
	../ctlr/inbound.c \
	../ctlr/oia.c \
	../ctlr/options.c \
	../ctlr/outbound.c \
	../general/genbsubs.c \
	../general/globals.c \
	../sys_curses/system.c \
	../sys_curses/termout.c

GENFILES=asc_disp.out astosc.out disp_asc.out kbd.out

CFLAGS+=-I../telnet
SRCS+=\
	../telnet/libtelnet/genget.c \
	../telnet/commands.c \
	../telnet/main.c \
	../telnet/network.c \
	../telnet/ring.c \
	../telnet/sys_bsd.c \
	../telnet/telnet.c \
	../telnet/terminal.c \
	../telnet/tn3270.c \
	../telnet/utilities.c

LIBS+=-lcurses
LIBS+=-lcrypt

include $(TOP)/mk/prog.mk

MKASTOSC=../tools/mkastosc/mkastosc
MKASTODS=../tools/mkastods/mkastods
MKDSTOAS=../tools/mkdstoas/mkdstoas
MKHITS=../tools/mkhits/mkhits

astosc.out: ${MKASTOSC} ../ctlr/hostctlr.h ../ctlr/function.h ../ctlr/${KBD}
	${MKASTOSC} ../ctlr/hostctlr.h ../ctlr/function.h \
	   < ../ctlr/${KBD} > astosc.tmp
	mv -f astosc.tmp ${.TARGET}

asc_disp.out: ${MKASTODS}
	${MKASTODS} > asc_disp.tmp
	mv -f asc_disp.tmp ${.TARGET}

disp_asc.out: ${MKDSTOAS}
	${MKDSTOAS} > disp_asc.tmp
	mv -f disp_asc.tmp ${.TARGET}

kbd.out: ${MKHITS} ../ctlr/hostctlr.h ../ctlr/${KBD} ../ctlr/function.c
	${CC} ${CPPFLAGS} -E ${.CURDIR}/../ctlr/function.c > kbd.tmp
	${MKHITS} ../ctlr/hostctlr.h kbd.tmp < ../ctlr/${KBD} > kbd.tmp2
	rm -f kbd.tmp
	mv -f kbd.tmp2 ${.TARGET}

clean: cleanhere
cleanhere:
	rm -f astosc.tmp asc_disp.tmp disp_asc.tmp kbd.tmp kbd.tmp2

# depend should catch these, but just in case
astosc.o:	astosc.out
disp_asc.o:	asc_disp.out disp_asc.out
inbound.o:	kbd.out
