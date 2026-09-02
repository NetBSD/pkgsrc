# $NetBSD: Makefile,v 1.57 2026/09/02 19:03:04 wiz Exp $

DISTNAME=	ibus-array-0.3.0
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=lexical/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lexical/ibus-array/
COMMENT=	Array 30 Input Method for iBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt msgmerge

PY_PATCHPLIST=	yes

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../converters/opencc/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
