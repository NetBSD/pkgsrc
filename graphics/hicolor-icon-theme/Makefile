# $NetBSD: Makefile,v 1.4 2004/12/22 09:21:45 minskim Exp $
#

DISTNAME=	hicolor-icon-theme-0.5
CATEGORIES=	graphics
MASTER_SITES=	http://freedesktop.org/software/icon-theme/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/icon-theme
COMMENT=	Standard icon theme called hicolor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
NO_BUILDLINK=	YES
NO_BUILD=	YES
USE_DIRS+=	xdg-1.1
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	# empty

.include "../../mk/bsd.pkg.mk"
