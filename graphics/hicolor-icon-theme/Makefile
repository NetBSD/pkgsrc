# $NetBSD: Makefile,v 1.7 2006/02/05 23:09:33 joerg Exp $
#

DISTNAME=	hicolor-icon-theme-0.5
PKGREVISION=	1
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
