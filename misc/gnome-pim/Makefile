# $NetBSD: Makefile,v 1.38 2003/05/05 16:43:42 jmmv Exp $

DISTNAME=		gnome-pim-1.4.6
PKGREVISION=		1
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pim/1.4/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Personal Information Manager for GNOME

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
