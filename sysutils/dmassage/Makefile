# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:40 jlam Exp $
#

DISTNAME=	dmassage-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
