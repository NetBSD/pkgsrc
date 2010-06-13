# $NetBSD: Makefile,v 1.47 2010/06/13 22:44:59 wiz Exp $

DISTNAME=		gperiodic-2.0.8
PKGREVISION=		5
CATEGORIES=		misc x11
MASTER_SITES=		# http://www.frantz.fi/software/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.frantz.fi/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS=	bin share/gnome/apps/Applications share/pixmaps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
