# $NetBSD: Makefile,v 1.7 2008/07/28 18:47:12 plunky Exp $
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
	${INSTALL_MAN} ${WRKSRC}/lcab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
