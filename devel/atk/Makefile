# $NetBSD: Makefile,v 1.54 2006/08/22 18:25:16 wiz Exp $
#

DISTNAME=		atk-1.12.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atk/1.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/projects/gap/
COMMENT=		Set of interfaces for accessibility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# remove on next update
DIST_SUBDIR=		atk-1.12.1v2

USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	atk.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir="${PREFIX}/share/doc"

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

# glib-mkenums overflows a 2048kb stack on atkobject.h
UNLIMIT_RESOURCES=	stacksize

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99         
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
