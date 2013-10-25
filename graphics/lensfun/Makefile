# $NetBSD: Makefile,v 1.25 2013/10/25 12:59:07 adam Exp $

DISTNAME=	lensfun-0.2.8
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/lensfun/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://lensfun.berlios.de/
COMMENT=	Library for rectifying defects introduced by photographic equipment
LICENSE=	gnu-lgpl-v3

# But, the build system looks for makedep, not makedepend.
# Defer, because cmake is coming.
BUILD_DEPENDS+=	makedepend-[0-9]*:../../devel/makedepend

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config gsed
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--vectorization=
MAKE_FILE=		GNUmakefile

CONFIG_SHELL=		${PYTHONBIN}
PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		configure
PKGCONFIG_OVERRIDE=	libs/lensfun/lensfun.pc.in

.include "../../mk/bsd.prefs.mk"

# Starting in 0.2.6, the library is misinstalled as liblensfun.so,
# with no .0 variant.  Manually fix it, because that's easier than
# understanding the build, and upstream is moving to cmake anyway.
post-install:
.if ${OPSYS} == "Darwin"
	${MV} ${DESTDIR}${PREFIX}/lib/liblensfun.dylib.${PKGVERSION_NOREV} \
		${DESTDIR}${PREFIX}/lib/liblensfun.${PKGVERSION_NOREV}.dylib
	${RM} ${DESTDIR}${PREFIX}/lib/liblensfun.dylib*
	${LN} -s liblensfun.${PKGVERSION_NOREV}.dylib \
		${DESTDIR}${PREFIX}/lib/liblensfun.0.dylib
	${LN} -s liblensfun.${PKGVERSION_NOREV}.dylib \
		${DESTDIR}${PREFIX}/lib/liblensfun.dylib
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# png: for test programs only
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
