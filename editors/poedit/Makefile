# $NetBSD: Makefile,v 1.64 2017/08/24 20:03:13 adam Exp $

DISTNAME=	poedit-1.8.7.1
PKGREVISION=	9
CATEGORIES=	editors
MASTER_SITES=	https://github.com/vslavik/poedit/releases/download/v${PKGVERSION_NOREV}-oss/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poedit.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor
LICENSE=	mit

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config zip:run
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		BDB_TYPE="${BDB_TYPE}"
CONFIGURE_ENV+=		WX_CONFIG_NAME=${BUILDLINK_PREFIX.wxGTK28}/bin/wx-config

CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/lucene++/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
