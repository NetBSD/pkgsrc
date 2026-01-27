# $NetBSD: Makefile,v 1.98 2026/01/27 08:39:55 wiz Exp $

GITHUB_PROJECT=	ibus-chewing
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DISTNAME=	ibus-chewing-1.5.1-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	25
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=definite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Chewing engine for IBus input platform
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
TOOLS_NOOP+=		msgmerge xgettext

MAKE_JOBS_SAFE=		no

BUILD_TARGET=	all translations

TEST_TARGET=	test

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/glib2/schemas.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
