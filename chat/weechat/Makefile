# $NetBSD: Makefile,v 1.38 2012/12/16 01:52:01 obache Exp $

DISTNAME=	weechat-0.3.9.2
PKGREVISION=	1
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
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tcl --disable-guile --disable-aspell
MAKE_ENV+=		INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q}
MAKE_ENV+=		PREFIX=${DESTDIR:Q}${PREFIX:Q}
LIBS.SunOS+=		-lnsl

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
