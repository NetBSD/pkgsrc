# $NetBSD: Makefile,v 1.27 2022/08/11 05:09:13 gutteridge Exp $

DISTNAME=	gcr-3.38.1
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gcr/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Library for crypto UI and related tasks
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_TOOLS+=		aclocal autoconf automake autopoint
USE_TOOLS+=		gdbus-codegen readlink
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc
CONFIGURE_ARGS+=	--enable-vala

PKGCONFIG_OVERRIDE+=	gck-1.pc.in
PKGCONFIG_OVERRIDE+=	gcr-base-3.pc.in
PKGCONFIG_OVERRIDE+=	gcr-ui.pc.in
PKGCONFIG_OVERRIDE+=	gcr-3.pc.in

TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
