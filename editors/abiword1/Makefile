# $NetBSD: Makefile,v 1.8 2004/04/25 02:19:17 snj Exp $
#
# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named either "AbiWord Personal" or some name completely unlike
# AbiSource's registered trademarks.

DISTNAME=	abiword-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.abisource.com/
COMMENT=	Open Source cross-platform word processor (version 1, older)

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

DIST_SUBDIR=	abisuite
ABIWORD_VERS=	1.0.5

CONFLICTS=	abiword-[0-9]* abiword2-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/abi
USE_BUILDLINK3=	yes
USE_X11=	# defined
USE_GNU_TOOLS+=	make
USE_GNU_ICONV=	# defined
GNU_CONFIGURE=	# defined
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=	--with-psiconv=${BUILDLINK_PREFIX.psiconv}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--without-libwmf
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

OS_CFLAGS=	${CFLAGS}

.if exists(/usr/include/inttypes.h)
OS_CFLAGS+=	-DHAVE_INTTYPE_H=1
.endif

MAKE_ENV+=	OS_CFLAGS="${OS_CFLAGS}"

MAKE_FLAGS+=	ABI_BUILD_VERSION="${ABIWORD_VERS}"
MAKE_FLAGS+=	UNIX_CAN_BUILD_STATIC=0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/psiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
