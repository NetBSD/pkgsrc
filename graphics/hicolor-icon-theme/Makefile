# $NetBSD: Makefile,v 1.6 2005/05/22 20:08:06 jlam Exp $
#

DISTNAME=	hicolor-icon-theme-0.5
CATEGORIES=	graphics
MASTER_SITES=	http://freedesktop.org/software/icon-theme/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/icon-theme
COMMENT=	Standard icon theme called hicolor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
NO_BUILD=	YES
USE_DIRS+=	xdg-1.1
USE_TOOLS+=	gmake
USE_LANGUAGES=	# empty

.include "../../mk/bsd.pkg.mk"
