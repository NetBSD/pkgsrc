# $NetBSD: Makefile,v 1.4 1999/06/07 16:16:17 hubertf Exp $
#

DISTNAME=		BladeEnc-076-bsd-i386
PKGNAME=		bladeenc-0.76
CATEGORIES=		audio
MASTER_SITES=		http://home.swipnet.se/~w-82625/encoder/binaries/
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bladeenc.cjb.net

NO_BUILD=

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bladeenc ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/BladeEnc.html ${PREFIX}/share/doc/bladeenc.html

.include "../../mk/bsd.pkg.mk"
