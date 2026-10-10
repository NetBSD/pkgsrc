# $NetBSD: Makefile,v 1.32 2026/10/10 11:26:50 adam Exp $

DISTNAME=	ibus-hangul-1.5.5
CATEGORIES=	inputmethod korean
MASTER_SITES=	${MASTER_SITE_GITHUB:=libhangul/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libhangul/ibus-hangul/wiki
COMMENT=	Hangul engine for IBus input platform
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

PY_PATCHPLIST=		yes

.include "../../mk/bsd.prefs.mk"
# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
