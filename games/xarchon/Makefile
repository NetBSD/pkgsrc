# $NetBSD: Makefile,v 1.24 2003/12/20 01:51:34 hubertf Exp $
#

DISTNAME=	xarchon-0.60
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://xarchon.seul.org/
COMMENT=	Chess-like strategy game with battle options

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES
USE_GCC_SHLIB=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	CC="${CC}"
.endif

#HF#DEPENDS+=	glade-[0-9]*:../../devel/glade
#HF#CONFIGURE_ENV+=	GTK_CONFIG=${X11PREFIX}/bin/gtk-config

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
#HF#.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
