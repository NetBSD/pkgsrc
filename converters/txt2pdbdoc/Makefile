# $NetBSD: Makefile,v 1.9 2014/05/29 23:35:24 wiz Exp $

DISTNAME=	txt2pdbdoc-1.4.4
PKGREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	http://homepage.mac.com/pauljlucas/software/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/pauljlucas/software/txt2pdbdoc/
COMMENT=	Text to Palm DOC converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4

.include "../../mk/bsd.pkg.mk"
