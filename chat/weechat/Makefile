# $NetBSD: Makefile,v 1.19 2008/05/11 19:10:30 tonio Exp $
#

DISTNAME=	weechat-0.2.6
CATEGORIES=	chat
MASTER_SITES=	http://weechat.flashtux.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://weechat.flashtux.org/
COMMENT=	Lightweight and user friendly curses based IRC client

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ruby --disable-perl --disable-aspell
MAKE_ENV+=		INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q}

INCOMPAT_CURSES+=	NetBSD-*-*

#LICENSE=		gplv3

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
