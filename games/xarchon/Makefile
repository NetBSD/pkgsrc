# $NetBSD: Makefile,v 1.49 2012/05/16 13:01:02 marino Exp $
#

DISTNAME=	xarchon-0.60
PKGREVISION=	10
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xarchon.seul.org/
COMMENT=	Chess-like strategy game with battle options

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	CC=${CC:Q}
.endif

LDFLAGS.DragonFly=	-lX11

.include "../../audio/esound/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
