# $NetBSD: Makefile,v 1.3 2001/09/09 20:36:11 agc Exp $
#

DISTNAME=		xfd_SZDD
PKGNAME=		szdd-1.3
CATEGORIES=		archivers
MASTER_SITES=		http://www.kyz.uklinux.net/downloads/
EXTRACT_SUFX=		.lha

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.kyz.uklinux.net/packers.php3#SZDD
COMMENT=		extracts Microsoft SZDD files

USE_BUILDLINK_ONLY=	yes
WRKSRC=			${WRKDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

do-install:
	${CP} ${WRKSRC}/szddexpand ${WRKSRC}/szddinfo ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
