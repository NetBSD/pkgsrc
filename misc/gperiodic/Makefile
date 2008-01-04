# $NetBSD: Makefile,v 1.43 2008/01/04 07:29:04 obache Exp $

DISTNAME=		gperiodic-2.0.8
PKGREVISION=		3
CATEGORIES=		misc x11
MASTER_SITES=		# http://www.frantz.fi/software/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.frantz.fi/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
BUILD_TARGET=		gperiodic

LIBS+=			-lintl
MAKE_ENV+=		LIBS=${LIBS:M*:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
