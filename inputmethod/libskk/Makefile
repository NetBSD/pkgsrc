# $NetBSD: Makefile,v 1.23 2026/09/02 19:03:07 wiz Exp $

DISTNAME=	libskk-1.0.5
PKGREVISION=	6
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueno/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueno/libskk/
COMMENT=	Library to deal with Japnese kana-to-kanji conversion method
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libskk/libskk.pc.in

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--enable-introspection=yes

TEST_TARGET=		check

CFLAGS+=		-Wno-incompatible-pointer-types
CFLAGS+=		-Wno-int-conversion

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.0
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
