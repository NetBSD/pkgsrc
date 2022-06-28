# $NetBSD: Makefile,v 1.5 2022/06/28 11:34:37 wiz Exp $

DISTNAME=	gcc-11.1.0
PKGNAME=	${DISTNAME:S/gcc/libquadmath/}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/${DISTNAME}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	GCC Quad-Precision Math Library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99 c++
USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

GNU_CONFIGURE_STRICT=	no

## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/libquadmath/configure
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--disable-multilib

PLIST_SUBST+=		NATIVE_MACHINE_GNU_PLATFORM=${NATIVE_MACHINE_GNU_PLATFORM}

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "../../mk/bsd.prefs.mk"

.if empty(PKGSRC_COMPILER:Mgcc*)
PKG_SKIP_REASON+=	"Uses esoteric GCC-specific features"
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
