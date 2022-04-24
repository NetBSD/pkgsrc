# $NetBSD: Makefile,v 1.46 2022/04/24 13:51:41 nia Exp $

DISTNAME=	ncmpc-0.46
CATEGORIES=	audio
MASTER_SITES=	https://musicpd.org/download/ncmpc/0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musicpd.org/clients/ncmpc/
COMMENT=	Fully featured musicpd client using curses
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config xgettext
USE_LANGUAGES=	c c++
FAKE_NCURSES=	yes

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:tool

MESON_ARGS+=	-Dlirc=disabled
MESON_ARGS+=	-Dhtml_manual=false

# C++17
GCC_REQD+=	7

# make stderr readable
CXXFLAGS+=	-Wno-undef

LDFLAGS+=	${BUILDLINK_LDADD.curses}

LDFLAGS.SunOS+=		-lintl -liconv -lsocket -lnsl
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
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
