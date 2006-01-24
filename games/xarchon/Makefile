# $NetBSD: Makefile,v 1.35 2006/01/24 07:32:09 wiz Exp $
#

DISTNAME=	xarchon-0.60
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xarchon.seul.org/
COMMENT=	Chess-like strategy game with battle options

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	CC=${CC:Q}
.endif

#HF#DEPENDS+=	glade-[0-9]*:../../devel/glade
#HF#CONFIGURE_ENV+=	GTK_CONFIG=${X11PREFIX}/bin/gtk-config

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
#HF#.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
