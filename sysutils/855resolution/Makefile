# $NetBSD: Makefile,v 1.7 2006/10/04 21:59:34 wiz Exp $
#

DISTNAME=	855resolution-0.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.orange.fr/apoirier/
COMMENT=	BIOS VESA resolution utility for 855/865/915 Intel chips

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=		${WRKDIR}/855resolution
USE_TOOLS+=	gmake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/855resolution
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/855resolution

.include "../../mk/bsd.pkg.mk"
