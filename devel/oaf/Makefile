# $NetBSD: Makefile,v 1.39 2004/11/20 22:10:23 jmmv Exp $
#

DISTNAME=		oaf-0.6.10
PKGREVISION=		6
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/oaf/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		New object activation framework for GNOME

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		lex yacc
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
