# $NetBSD: Makefile,v 1.24 2004/04/28 05:33:58 snj Exp $

DISTNAME=		gperiodic-2.0.7
PKGREVISION=		2
CATEGORIES=		misc x11
MASTER_SITES=		http://www.acclab.helsinki.fi/~frantz/software/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.acclab.helsinki.fi/~frantz/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
USE_GNU_TOOLS+=		make

BUILDLINK_TRANSFORM+=	S:-DG_DISABLE_DEPRECATED:
BUILDLINK_TRANSFORM+=	S:-DGDK_DISABLE_DEPRECATED:
BUILDLINK_TRANSFORM+=	S:-DGDK_PIXBUF_DISABLE_DEPRECATED:
BUILDLINK_TRANSFORM+=	S:-DGTK_DISABLE_DEPRECATED:

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
ALL_TARGET=		gperiodic

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
