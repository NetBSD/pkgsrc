# $NetBSD: Makefile,v 1.6 2007/05/28 21:23:47 wiz Exp $
#

DISTNAME=		lcab-1.0b10
CATEGORIES=		archivers
MASTER_SITES=		http://coding.wooyayhoopla.be/lcab/sources/

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://coding.wooyayhoopla.be/lcab/
COMMENT=		Microsoft cabinet (.CAB) file creator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
