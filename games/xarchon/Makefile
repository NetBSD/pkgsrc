# $NetBSD: Makefile,v 1.59 2016/02/25 13:19:47 jperkin Exp $
#

DISTNAME=	xarchon-0.60
PKGREVISION=	18
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xarchon.seul.org/
COMMENT=	Chess-like strategy game with battle options

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

CONFIGURE_ENV.SunOS+=	CC=${CC:Q}
LDFLAGS.DragonFly=	-lX11
LIBS.SunOS+=		-lX11 -lsocket -lnsl

.include "../../audio/esound/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
