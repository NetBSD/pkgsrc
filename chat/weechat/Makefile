# $NetBSD: Makefile,v 1.44 2014/01/01 11:52:11 wiz Exp $

DISTNAME=	weechat-0.4.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://www.weechat.org/files/src/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.weechat.org/
COMMENT=	Lightweight and user friendly curses based IRC client
LICENSE=	gnu-gpl-v3
EXTRACT_SUFX=	.tar.bz2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_CMAKE=		yes

CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
LDFLAGS.SunOS+=		-lsocket -lnsl -lintl

CMAKE_ARGS+=		-DENABLE_ASPELL:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_GUILE:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_TCL:BOOL=OFF
CMAKE_ARGS+=		-DMANDIR:STRING=${PKGMANDIR}
CMAKE_ARGS+=		-DLOCALEDIR:STRING=${PKGLOCALEDIR}/locale

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
