# $NetBSD: Makefile,v 1.43 2004/01/03 18:49:46 reed Exp $

DISTNAME=		gnome-pim-1.4.6
PKGREVISION=		5
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pim/1.4/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Personal Information Manager for GNOME

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		LOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE}

.include "../../comms/gnome-pilot/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
