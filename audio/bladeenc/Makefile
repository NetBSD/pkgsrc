# $NetBSD: Makefile,v 1.2 1998/12/28 19:16:50 tv Exp $
#

DISTNAME=	BladeEnc-076-bsd-i386
PKGNAME=	bladeenc-0.76
CATEGORIES=	audio
MASTER_SITES=	http://home.swipnet.se/~w-82625/encoder/binaries/
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://bladeenc.home.ml.org/

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bladeenc ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/BladeEnc.html ${PREFIX}/share/doc/bladeenc.html

.include "../../mk/bsd.pkg.mk"
