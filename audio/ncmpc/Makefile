# $NetBSD: Makefile,v 1.35 2019/10/21 21:19:35 adam Exp $

DISTNAME=	ncmpc-0.35
CATEGORIES=	audio
MASTER_SITES=	https://musicpd.org/download/ncmpc/0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musicpd.org/clients/ncmpc/
COMMENT=	Fully featured musicpd client using curses
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config xgettext
USE_LANGUAGES=	c c++14
FAKE_NCURSES=	yes

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:tool

MESON_ARGS+=	-Dlirc=disabled
MESON_ARGS+=	-Dhtml_manual=false

# C++14
GCC_REQD+=	4.9

# make stderr readable
CXXFLAGS+=	-Wno-noexcept-type
CXXFLAGS+=	-Wno-undef

LDFLAGS+=	${BUILDLINK_LDADD.curses}

LDFLAGS.SunOS+=		-lintl
LDFLAGS.NetBSD+=	-lintl

PYTHON_FOR_BUILD_ONLY=	tool

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Set Python version variables.
SUBST_FILES.py+=	doc/meson.build
SUBST_VARS.py+=		PYVERSSUFFIX

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
