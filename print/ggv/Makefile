# $NetBSD: Makefile,v 1.46 2004/03/08 19:40:42 jmmv Exp $
#

DISTNAME=		ggv-1.0.2
PKGREVISION=		12
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ggv/1.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME frontend for GhostScript

BUILD_USES_MSGFMT=	YES
DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11BASE=		YES

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
