# $NetBSD: Makefile,v 1.44 2012/10/03 11:43:42 asau Exp $

DISTNAME=	poedit-1.4.6.1
PKGREVISION=	13
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

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

.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
