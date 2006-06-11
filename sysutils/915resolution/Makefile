# $NetBSD: Makefile,v 1.1.1.1 2006/06/11 14:03:58 markd Exp $
#

DISTNAME=	915resolution-0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/stomljen/
COMMENT=	BIOS VESA resolution utility for 8XX/9XX Intel chips

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_TOOLS+=	gmake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/915resolution
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/915resolution

.include "../../mk/bsd.pkg.mk"
