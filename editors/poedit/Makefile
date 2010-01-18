# $NetBSD: Makefile,v 1.27 2010/01/18 09:58:48 wiz Exp $
#

DISTNAME=	poedit-1.4.2
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poedit.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ENV+=		WX_CONFIG_NAME=${BUILDLINK_PREFIX.wxGTK28}/bin/wx-config

.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
