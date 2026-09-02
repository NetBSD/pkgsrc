# $NetBSD: Makefile,v 1.29 2026/09/02 19:03:04 wiz Exp $
#

DISTNAME=	ibus-hangul-1.5.0
PKGREVISION=	8
CATEGORIES=	inputmethod korean
MASTER_SITES=	${MASTER_SITE_GITHUB:=choehwanjin/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Hangul engine for IBus input platform
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt intltool

PY_PATCHPLIST=		yes

# uses deprecated imp module
PYTHON_VERSIONS_ACCEPTED=	311 310

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.1.0
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
