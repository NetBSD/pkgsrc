# $NetBSD: Makefile,v 1.1 2026/04/06 13:46:38 nia Exp $

DISTNAME=	nchat-5.14.44
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=d99kris/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/d99kris/nchat
COMMENT=	Terminal-based Telegram messaging client
LICENSE=	mit

DEPENDS+=		${PYPKGPREFIX}-urllib3>=0:../../www/py-urllib3
TOOL_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14

# go required ... messy
CMAKE_CONFIGURE_ARGS+=	-DHAS_SIGNAL=OFF
CMAKE_CONFIGURE_ARGS+=	-DHAS_WHATSAPP=OFF

CMAKE_CONFIGURE_ARGS+=	-DCURSES_INCLUDE_PATH=${BUILDLINK_INCDIRS.curses}

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}
LDFLAGS.NetBSD+=	-lexecinfo # backtrace

# Refuses to build the Telegram module on big-endian, making
# it quite useless.
NOT_FOR_PLATFORM+=	${BIGENDIANPLATFORMS}

REPLACE_PYTHON+=	src/compose

FAKE_NCURSES=		yes
.include "../../mk/curses.buildlink3.mk"

.if !${CURSES_TYPE:M*ncurses*}
BUILDLINK_TRANSFORM+=	l:gnuform:form
.endif

INSTALLATION_DIRS+=	lib/${PKGBASE}

post-install:
	${MV} ${DESTDIR}${PREFIX}/lib/*.${SHLIB_EXT}* \
		${DESTDIR}${PREFIX}/lib/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/atomic64.mk"
PTHREAD_OPTS?=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
