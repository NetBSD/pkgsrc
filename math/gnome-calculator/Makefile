# $NetBSD: Makefile,v 1.49 2020/11/05 09:08:37 ryoon Exp $

DISTNAME=		gnome-calculator-3.24.0
PKGREVISION=		27
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-calculator/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://wiki.gnome.org/Apps/Calculator
COMMENT=		Desktop calculator for GNOME
LICENSE=		gnu-gpl-v2

DEPENDS+=		gnome-icon-theme-symbolic-[0-9]*:../../graphics/gnome-icon-theme-symbolic
BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

CONFLICTS+=		gcalctool-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+=		libsoup>=2.42
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.19.3
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview3+=	gtksourceview3>=3.15.1
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
