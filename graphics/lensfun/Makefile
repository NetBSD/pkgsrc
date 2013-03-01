# $NetBSD: Makefile,v 1.23 2013/03/01 14:49:53 gdt Exp $
#

DISTNAME=	lensfun-0.2.7
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

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--vectorization=
MAKE_FILE=		GNUmakefile

CONFIG_SHELL=		${PYTHONBIN}
PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		configure
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config gsed
PKGCONFIG_OVERRIDE=	libs/lensfun/lensfun.pc.in

# Starting in 0.2.6, the library is misinstalled as liblensfun.so,
# with no .0 variant.  Manually fix it, because that's easier than
# understanding the build, and upstream is moving to cmake anyway.
post-install:
	${MV} ${DESTDIR}${PREFIX}/lib/liblensfun.so \
		${DESTDIR}${PREFIX}/lib/liblensfun.so.${PKGVERSION:C/nb[0-9]*//}
	${LN} -s liblensfun.so.${PKGVERSION:C/nb[0-9]*//} \
		${DESTDIR}${PREFIX}/lib/liblensfun.so.0
	${LN} -s liblensfun.so.${PKGVERSION:C/nb[0-9]*//} \
		${DESTDIR}${PREFIX}/lib/liblensfun.so

.include "../../devel/glib2/buildlink3.mk"
# png: for test programs only
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
# DO NOT DELETE
