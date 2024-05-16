# $NetBSD: Makefile,v 1.146 2024/05/16 06:14:38 wiz Exp $

DISTNAME=	weechat-4.2.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://www.weechat.org/files/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://www.weechat.org/
COMMENT=	Lightweight and user friendly curses based IRC client
LICENSE=	gnu-gpl-v3

.include "../../lang/ruby/rubyversion.mk"

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

PYTHON_VERSIONS_INCOMPATIBLE=	27
USE_TOOLS+=	msgfmt pkg-config
USE_LANGUAGES=	c99
USE_CMAKE=	yes
FAKE_NCURSES=	yes

CMAKE_ARGS+=	-DASCIIDOCTOR_FOUND=ON
CMAKE_ARGS+=	-DASCIIDOCTOR_EXECUTABLE=${PREFIX}/bin/asciidoctor${RUBY_VER}
CMAKE_ARGS+=	-DENABLE_GUILE=OFF
CMAKE_ARGS+=	-DENABLE_TCL=OFF
CMAKE_ARGS+=	-DENABLE_JAVASCRIPT=OFF
CMAKE_ARGS+=	-DENABLE_PHP=OFF
CMAKE_ARGS+=	-DENABLE_SPELL=OFF
CMAKE_ARGS+=	-DENABLE_CHARSET=ON
CMAKE_ARGS+=	-DENABLE_MAN=ON
CMAKE_ARGS+=	-DLOCALEDIR=${PKGLOCALEDIR}/locale
CMAKE_ARGS+=	-DMANDIR=${PREFIX}/${PKGMANDIR}

USE_PKGLOCALEDIR=	yes

LDFLAGS+=		${BUILDLINK_LDADD.gettext}
LDFLAGS.Darwin+=	-lresolv
LDFLAGS.SunOS+=		-lresolv
LDFLAGS.NetBSD+=	-Wl,--copy-dt-needed-entries

BUILDLINK_TRANSFORM+=	rm:-Werror-implicit-function-declaration

.include "options.mk"

.if !empty(PKG_OPTIONS:Mpython)
SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Adjusting pkg-config python checks
SUBST_FILES.python=	cmake/FindPython.cmake
SUBST_SED.python=	-e 's,python3,python-${PYVERSSUFFIX},g'
.endif

pre-configure:
	# Use the standard cmake mechanism for finding Lua.
	${RM} -f ${WRKSRC}/cmake/FindLua.cmake

.include "../../archivers/zstd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
