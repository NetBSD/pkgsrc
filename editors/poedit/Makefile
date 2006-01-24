# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:06 wiz Exp $
#

DISTNAME=	poedit-1.3.4
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.2 gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ENV+=		WX_CONFIG_NAME=${BUILDLINK_PREFIX.wxGTK}/bin/wx-config

.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
