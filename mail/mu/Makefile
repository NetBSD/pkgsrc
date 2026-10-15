# $NetBSD: Makefile,v 1.33 2026/10/15 13:06:37 ktnb Exp $

DISTNAME=	mu-1.14.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=djcb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.djcbsoftware.nl/code/mu/
COMMENT=	E-mail searching and indexing tools
LICENSE=	gnu-gpl-v3

MESON_ARGS+=	-Dinfodir=${PKGINFODIR}
MESON_ARGS+=	-Dlispdir=${EMACS_LISPPREFIX}
USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config makeinfo
ICON_THEMES=	yes
# mu4e textinfo uses newer features
TEXINFO_REQD+=	7.0

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		build-aux/date.py

USE_CXX_FEATURES+=	c++20 charconv

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/CLI11/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.80.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/tl-expected/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
