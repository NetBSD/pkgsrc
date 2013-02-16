# $NetBSD: Makefile,v 1.18 2013/02/16 11:22:16 wiz Exp $
#

DISTNAME=	lensfun-0.2.5
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/lensfun/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lensfun.berlios.de/
COMMENT=	Library for rectifying defects introduced by photographic equipment
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	makedepend-[0-9]*:../../devel/makedepend

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--vectorization=
CONFIG_SHELL=		${PYTHONBIN}
MAKE_FILE=		GNUmakefile
PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		configure
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config gsed
PKGCONFIG_OVERRIDE=	libs/lensfun/lensfun.pc.in

# Why three copys of the file?
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/liblensfun.so
	${RM} -f ${DESTDIR}${PREFIX}/lib/liblensfun.so.0
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
