# $NetBSD: Makefile,v 1.24 2009/07/22 09:01:25 wiz Exp $
#

DISTNAME=	poedit-1.3.6
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poedit.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=	zip-[0-9]*:../../archivers/zip

BROKEN=		Requires Unicode version of wxGTK

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ENV+=		WX_CONFIG_NAME=${BUILDLINK_PREFIX.wxGTK}/bin/wx-config

.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
