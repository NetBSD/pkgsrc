# $NetBSD: Makefile,v 1.38 2005/05/10 16:37:16 drochner Exp $
#

DISTNAME=		atk-1.10.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atk/1.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/projects/gap/
COMMENT=		Set of interfaces for accessibility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	atk.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir="${PREFIX}/share/doc"

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

# glib-mkenums overflows a 2048kb stack on atkobject.h
UNLIMIT_RESOURCES=	stacksize

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
