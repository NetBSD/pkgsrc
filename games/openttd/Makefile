# $NetBSD: Makefile,v 1.27.4.1 2008/08/20 09:43:10 tron Exp $

DISTNAME=	openttd-0.6.2-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openttd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openttd.com/
COMMENT=	Open source clone of Transport Tycoon Deluxe
EXTRACT_SUFX=	.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--prefix-dir=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--binary-dir=bin
CONFIGURE_ARGS+=	--data-dir=share/openttd

# disable custom assert for Mac OS X (XXX: still needed?)
CFLAGS+=	-DNDEBUG=1

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=	bundle

post-install:
	rm -rf ${FAKEHOMEDIR}/.openttd

.include "options.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
