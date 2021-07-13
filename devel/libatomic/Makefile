# $NetBSD: Makefile,v 1.4 2021/07/13 07:53:38 nia Exp $

DISTNAME=	gcc-10.3.0
PKGNAME=	${DISTNAME:S/gcc/libatomic/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/${DISTNAME}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	Atomic fallback implementation for GCC
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE_STRICT=	no
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/libatomic/configure

CONFIGURE_ARGS+=	--disable-multilib

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "../../mk/bsd.prefs.mk"

.if empty(PKGSRC_COMPILER:Mgcc*)
PKG_SKIP_REASON+=	"Uses esoteric GCC-specific features"
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
