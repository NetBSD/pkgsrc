# $NetBSD: Makefile,v 1.7 2024/01/24 20:12:00 wiz Exp $

DISTNAME=	zlib-1.3.1
PKGNAME=	${DISTNAME:S/zlib-/minizip-/1}
CATEGORIES=	archivers
MASTER_SITES=	http://zlib.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winimage.com/zLibDll/minizip.html
COMMENT=	Zip file manipulation library from the zlib distribution
LICENSE=	zlib

WRKSRC=		${WRKDIR}/zlib-${PKGVERSION_NOREV}/contrib/minizip

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CPPFLAGS+=	-DUSE_FILE32API
.endif

PKGCONFIG_OVERRIDE+=	minizip.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

# https://github.com/madler/zlib/pull/229
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/minizip/crypt.h

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
