# $NetBSD: Makefile,v 1.47 2002/07/03 21:59:07 hubertf Exp $
#
# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named either "AbiWord Personal" or some name completely unlike
# AbiSource's registered trademarks.

DISTNAME=	abiword-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.abisource.com/
COMMENT=	Open Source cross-platform word processor

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

DIST_SUBDIR=	abisuite
ABIWORD_VERS=	1.0.2

USE_BUILDLINK_ONLY=	# defined
USE_X11=	# defined
USE_GMAKE=	# defined
HAS_CONFIGURE=	# defined
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-psiconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_DIR}
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

WRKSRC=		${WRKDIR}/${DISTNAME}/abi

FILES_SUBST=		LN=${LN:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

.include "../../converters/libiconv/buildlink.mk"
.include "../../converters/psiconv/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../textproc/expat/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
