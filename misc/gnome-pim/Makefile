# $NetBSD: Makefile,v 1.48 2004/04/26 05:22:32 snj Exp $

DISTNAME=		gnome-pim-1.4.6
PKGREVISION=		7
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pim/1.4/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Personal Information Manager for GNOME

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11BASE=		YES
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		LOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE}

.include "../../comms/gnome-pilot/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
