# $NetBSD: Makefile,v 1.43 2004/01/03 18:49:51 reed Exp $
#

DISTNAME=		ggv-1.0.2
PKGREVISION=		11
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ggv/1.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME frontend for GhostScript

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
