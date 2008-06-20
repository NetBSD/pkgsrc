# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:29 joerg Exp $

PROG	= dip
PROG1	= diplogin
LINKS	= ${BINDIR}/${PROG} ${BINDIR}/${PROG1}
VERSION	= 1.01

BINTGT	= dip
BINDIR	= ${PREFIX}/sbin

MAN		= dip.8
MLINKS		= dip.8 diplogin.8
MANINSTALL	= maninstall catinstall

SAMPLES	= samples/dialout.dip.sample  samples/ReadMe.HowTo    \
	  samples/sample2.dip         samples/diphosts        \
	  samples/sample.dip          samples/setup.sh.sample \
	  samples/ReadMe              samples/sample1.dip     \
	  samples/startup.sh.sample

SMPDIR	= ${PREFIX}/lib/dip

# OWNSLEEP= -DUSEOWNSLEEP

SRCS	= attach.c command.c config.c daemon.c dip.c login.c modem.c ppp.c\
	  slip.c term.c tty.c

.ifdef (OWNSLEEP)
SRCS	+= sleep.c
.endif

afterinstall:
	@if [ ! -d ${DESTDIR}${SMPDIR} ] ; then mkdir -p ${DESTDIR}${SMPDIR} ; fi
	${BSD_INSTALL_DATA} ${SAMPLES} ${DESTDIR}${SMPDIR}

.include <bsd.prog.mk>
