# $NetBSD: Makefile,v 1.7 2019/06/08 11:04:28 rillig Exp $

GCCVER=		4.9.2
DISTNAME=	ghdl-0.32rc1
CATEGORIES=	cad
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2
GCCDISTNAME=	gcc-${GCCVER}.tar.bz2
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${GCCDISTNAME}
SITES.${GCCDISTNAME}= \
	${MASTER_SITE_GNU:=gcc/gcc-${GCCVER}/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/p/ghdl-updates/wiki/Home/
COMMENT=	Open-source simulator for the VHDL language
LICENSE=	gnu-gpl-v2

# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
TOOLS_PLATFORM.makeinfo=

WRKSRC=		${WRKDIR}/gcc-${GCCVER}

USE_LANGUAGES=	c c++ ada

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makeinfo
INFO_FILES=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-languages=vhdl
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}

## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../gcc-${GCCVER}/configure

GCC_PKGNAME=		gcc49-ghdl
GCC_SUBPREFIX=		${GCC_PKGNAME}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${GCC_PREFIX}

CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}

INSTALLATION_DIRS+=	bin

post-extract:
	cd ${WRKDIR} && ${MV} ${DISTNAME}/vhdl gcc-${GCCVER}/gcc

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -fs ../gcc49-ghdl/bin/ghdl .

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
