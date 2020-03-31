# $NetBSD: Makefile,v 1.1 2020/03/31 10:25:28 nia Exp $

DISTNAME=	zlib-1.2.11
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

PKGCONFIG_OVERRIDE+=	minizip.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

# https://github.com/madler/zlib/pull/229
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/minizip/crypt.h

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
