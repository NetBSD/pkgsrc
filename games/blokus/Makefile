# $NetBSD: Makefile,v 1.13 2023/08/02 19:21:52 nia Exp $
#

DISTNAME=	blokus-1.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.saschahlusiak.de/blokus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.saschahlusiak.de/blokus/
COMMENT=	Abstract strategy board game for two to four players

RESTRICTED=		Redistribution prohibited
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
# XXX: For some reason, the other libraries are hidden when this is
# specified.
#LIBS.SunOS+=	-lGLU

# Fails with C++14 default language
FORCE_CXX_STD=	c++03

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
