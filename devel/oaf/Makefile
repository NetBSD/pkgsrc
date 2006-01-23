# $NetBSD: Makefile,v 1.42 2006/01/23 13:47:29 joerg Exp $
#

DISTNAME=		oaf-0.6.10
PKGREVISION=		6
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/oaf/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		New object activation framework for GNOME

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_TOOLS+=		bison lex
USE_LIBTOOL=		YES

BROKEN_GETTEXT_DETECTION=	YES

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
