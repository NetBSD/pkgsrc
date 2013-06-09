# $NetBSD: Makefile,v 1.41 2013/06/09 21:19:02 tonio Exp $

DISTNAME=	weechat-0.4.1
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
USE_LIBTOOL=		yes
USE_CMAKE=		yes
LIBS.SunOS+=		-lnsl

CMAKE_ARGS+=		-DENABLE_ASPELL:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_GUILE:BOOL=OFF
CMAKE_ARGS+=		-DENABLE_TCL:BOOL=OFF
CMAKE_ARGS+=		-DMANDIR:STRING=${PKGMANDIR}

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
