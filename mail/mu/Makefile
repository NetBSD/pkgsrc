# $NetBSD: Makefile,v 1.3 2024/05/15 10:33:08 wiz Exp $

DISTNAME=	mu-1.12.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=djcb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.djcbsoftware.nl/code/mu/
COMMENT=	E-mail searching and indexing tools
LICENSE=	gnu-gpl-v3

MESON_ARGS+=	-Dinfodir=info
MESON_ARGS+=	-Dlispdir=${EMACS_LISPPREFIX}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		build-aux/date.py

USE_CXX_FEATURES+=	c++17

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
