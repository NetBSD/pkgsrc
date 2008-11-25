# $NetBSD: Makefile,v 1.1 2008/11/25 13:21:48 bjs Exp $

# NOTE:  BINDIR, MKHTML, NOGCCERROR, and BINDIR set by pkgsrc Makefile

PROGS= 		usbctl usbdebug usbstats usbgen 

CPPFLAGS+=	-Wall	# In keeping with original Makefile

.for p in ${PROGS}
MAN.${p}?=	# empty
.endfor
MAN.usbgen=	usbgen.8

.include <bsd.prog.mk>
