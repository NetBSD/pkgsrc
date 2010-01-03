# $NetBSD: Makefile,v 1.34 2010/01/03 12:07:58 obache Exp $

DISTNAME=	openttd-0.7.2-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openttd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openttd.org/
COMMENT=	Open source clone of Transport Tycoon Deluxe
EXTRACT_SUFX=	.tar.bz2

HAS_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

# Setting the below results in binaries looking in ${DESTDIR} for datafiles
# CONFIGURE_ARGS+=	--prefix-dir=${DESTDIR}${PREFIX}
# PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--prefix-dir=${PREFIX}
CONFIGURE_ARGS+=	--binary-dir=bin
CONFIGURE_ARGS+=	--data-dir=share/openttd
CONFIGURE_ARGS+=	--man-dir=${PKGMANDIR}/man6

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "DragonFly")
CONFIGURE_ARGS+=	--os=FREEBSD
.endif

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
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
