# $NetBSD: Makefile,v 1.3 2005/07/16 01:19:20 jlam Exp $
#

DISTNAME=	dmassage-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sentia.org/projects/dmassage/
COMMENT=	dmesg(8) parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	dmassage

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dmassage ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
