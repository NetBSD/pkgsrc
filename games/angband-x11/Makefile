# $NetBSD: Makefile,v 1.1 1998/08/27 13:22:08 garbled Exp $
#

DISTNAME=		angband-283
PKGNAME=		angband-x11-2.8.3
CATEGORIES=		games x11
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net

WRKSRC=			../angband-tty/work/${DISTNAME}/src

NO_CHECKSUM=		yes
USE_X11=		yes
MAKEFILE=		Makefile.std
ALL_TARGET=		angband

do-fetch: # empty
do-extract:
	@mkdir work
	(cd ../angband-tty && make clean && make patch)

do-install:
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/angband
	${CP} -R ../angband-tty/work/${DISTNAME}/lib/* ${PREFIX}/share/angband
	chown -R bin:games ${PREFIX}/share/angband
	chmod -R 0664 ${PREFIX}/share/angband/*
	(cd ${PREFIX}/share/angband && chmod 0775 apex bone data edit file help info save user xtra)
	${INSTALL} -c -s -o bin -g games -m 2755 ${WRKSRC}/angband ${PREFIX}/bin

do-clean:
	@rm -rf work

.include "../../mk/bsd.pkg.mk"
