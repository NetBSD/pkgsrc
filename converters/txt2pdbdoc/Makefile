# $NetBSD: Makefile,v 1.3 2006/10/29 18:07:48 minskim Exp $

DISTNAME=	txt2pdbdoc-1.4.4
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://homepage.mac.com/pauljlucas/software/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/pauljlucas/software/txt2pdbdoc/
COMMENT=	Text to Palm DOC converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin man/man1 man/man4

.include "../../mk/bsd.pkg.mk"
