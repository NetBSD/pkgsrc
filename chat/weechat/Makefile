# $NetBSD: Makefile,v 1.60 2016/02/14 12:52:13 ryoon Exp $

DISTNAME=	weechat-1.4
CATEGORIES=	chat
MASTER_SITES=	http://www.weechat.org/files/src/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.weechat.org/
COMMENT=	Lightweight and user friendly curses based IRC client
LICENSE=	gnu-gpl-v3
EXTRACT_SUFX=	.tar.bz2

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_CMAKE=		yes

CMAKE_ARGS+=		-DENABLE_ASPELL:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_GUILE:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_TCL:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_MAN:BOOL=ON
CMAKE_ARGS+=		-DENABLE_V8:BOOL=OFF
CMAKE_ARGS+=		-DMANDIR:STRING=${PKGMANDIR}
CMAKE_ARGS+=		-DLOCALEDIR:STRING=${PKGLOCALEDIR}/locale
CMAKE_ARGS+=		-DENABLE_CHARSET:BOOL=ON

LDFLAGS+=		${BUILDLINK_LDADD.gettext}

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
