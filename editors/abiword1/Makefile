# $NetBSD: Makefile,v 1.1.1.1 2003/12/26 18:20:27 wiz Exp $
#
# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named either "AbiWord Personal" or some name completely unlike
# AbiSource's registered trademarks.

DISTNAME=	abiword-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${DISTNAME}/abi
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.abisource.com/
COMMENT=	Open Source cross-platform word processor

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

DIST_SUBDIR=	abisuite
ABIWORD_VERS=	1.0.5

USE_BUILDLINK2=	# defined
USE_X11=	# defined
USE_GMAKE=	# defined
USE_GNU_ICONV=	# defined
GNU_CONFIGURE=	# defined
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=	--with-psiconv=${BUILDLINK_PREFIX.psiconv}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--without-libwmf
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

OS_CFLAGS=	${CFLAGS}

.if exists(/usr/include/inttypes.h)
OS_CFLAGS+=	-DHAVE_INTTYPE_H=1
.endif

MAKE_ENV+=	OS_CFLAGS="${OS_CFLAGS}"

MAKE_FLAGS+=	ABI_BUILD_VERSION="${ABIWORD_VERS}"
MAKE_FLAGS+=	UNIX_CAN_BUILD_STATIC=0

.include "../../converters/libiconv/buildlink2.mk"

.if defined(ICONV_IS_GNU)
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
.endif

.include "../../converters/psiconv/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
