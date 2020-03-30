# $NetBSD: Makefile,v 1.112 2020/03/30 09:31:52 nia Exp $

DISTNAME=	weechat-2.8
CATEGORIES=	chat
MASTER_SITES=	https://www.weechat.org/files/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://www.weechat.org/
COMMENT=	Lightweight and user friendly curses based IRC client
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	msgfmt pkg-config
USE_LANGUAGES=	c99
USE_CMAKE=	yes
FAKE_NCURSES=	yes

CMAKE_ARGS+=	-DCA_FILE=${PREFIX}/share/mozilla-rootcerts/cacert.pem
CMAKE_ARGS+=	-DENABLE_GUILE=OFF
CMAKE_ARGS+=	-DENABLE_TCL=OFF
CMAKE_ARGS+=	-DENABLE_MAN=OFF # Requires ascii-doctor
CMAKE_ARGS+=	-DENABLE_JAVASCRIPT=OFF
CMAKE_ARGS+=	-DENABLE_PHP=OFF
CMAKE_ARGS+=	-DENABLE_SPELL=OFF
CMAKE_ARGS+=	-DLOCALEDIR=${PKGLOCALEDIR}/locale
CMAKE_ARGS+=	-DENABLE_CHARSET=ON

USE_PKGLOCALEDIR=	yes

LDFLAGS+=		${BUILDLINK_LDADD.gettext}
LDFLAGS.Darwin+=	-lresolv
LDFLAGS.SunOS+=		-lresolv

BUILDLINK_TRANSFORM+=	rm:-Werror-implicit-function-declaration

# use standard cmake mechanisms for detecting python
# works better with pkgsrc.
pre-configure:
	${RM} -f ${WRKSRC}/cmake/FindPython.cmake

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
