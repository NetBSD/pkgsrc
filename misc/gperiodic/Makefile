# $NetBSD: Makefile,v 1.35 2005/08/26 13:59:21 grant Exp $

DISTNAME=		gperiodic-2.0.8
CATEGORIES=		misc x11
MASTER_SITES=		http://www.acclab.helsinki.fi/~frantz/software/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.acclab.helsinki.fi/~frantz/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements

BUILD_USES_MSGFMT=	# defined

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	# defined
USE_TOOLS+=		gmake pkg-config

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
BUILD_TARGET=		gperiodic

LIBS+=			-lintl
MAKE_ENV+=		LIBS=${LIBS:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
