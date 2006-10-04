# $NetBSD: Makefile,v 1.5 2006/10/04 20:45:46 wiz Exp $
#

DISTNAME=		lcab-1.0b10
CATEGORIES=		archivers
MASTER_SITES=		http://www.geekshop.be/rien/lcab/files/

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.geekshop.be/rien/lcab/
COMMENT=		Microsoft cabinet (.CAB) file creator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
