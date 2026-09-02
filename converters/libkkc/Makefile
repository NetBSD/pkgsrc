# $NetBSD: Makefile,v 1.16 2026/09/02 19:01:14 wiz Exp $

GITHUB_PROJECT=	libkkc
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	libkkc-0.3.5
PKGREVISION=	7
CATEGORIES=	converters textproc japanese inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueno/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueno/libkkc/
COMMENT=	Japanese Kana Kanji conversion library
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection
TOOL_DEPENDS+=	${PYPKGPREFIX}-marisa-[0-9]*:../../textproc/py-marisa

PYTHON_VERSIONS_ACCEPTED=	27 # py-marisa

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libkkc/kkc-1.0.pc.in

TEST_TARGET=	check

CFLAGS+=	-Wno-incompatible-pointer-types
CFLAGS+=	-Wno-int-conversion

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
