# $NetBSD: Makefile,v 1.63 2025/01/03 04:14:02 gutteridge Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.20.0
DISTNAME=	xfce4-dev-tools-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://archive.xfce.org/src/xfce/xfce4-dev-tools/${VERSION:R}/

HOMEPAGE=	http://users.xfce.org/~benny/projects/xfce4-dev-tools/
COMMENT=	Xfce development tools

USE_TOOLS+=		bash:run
REPLACE_BASH+=		helpers/xfce-build helpers/xfce-do-release.in
REPLACE_BASH+=		helpers/xfce-get-release-notes
REPLACE_BASH+=		helpers/xfce-get-translations helpers/xfce-update-news
REPLACE_BASH+=		scripts/xdt-check-abi
REPLACE_PYTHON+=	scripts/xdt-gen-visibility

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
# This looks unorthodox, because meson isn't actually required to build
# this package; rather, the configure script expects it to be present in
# the environment as a validation, and will fail without it.
TOOL_DEPENDS+=	meson-[0-9]*:../../devel/meson

GNU_CONFIGURE=	yes

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
