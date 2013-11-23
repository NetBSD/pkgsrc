# $NetBSD: Makefile,v 1.1 2013/11/23 15:10:26 ryoon Exp $

DISTNAME=	ghdl-0.29
CATEGORIES=	cad
MASTER_SITES=	http://ghdl.free.fr/
EXTRACT_SUFX=	.tar.bz2
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} gcc-core-4.3.4.tar.bz2
SITES.gcc-core-4.3.4.tar.bz2=	${MASTER_SITE_GNU:=gcc/gcc-4.3.4/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ghdl.free.fr/
COMMENT=	Open-source simulator for the VHDL language
LICENSE=	gnu-gpl-v2

# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
TOOLS_PLATFORM.makeinfo=

WRKSRC=		${WRKDIR}/gcc-4.3.4

USE_LANGUAGES=	c ada

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
CONFIGURE_SCRIPT=	../gcc-4.3.4/configure

GCC_PKGNAME=		gcc43-ghdl
GCC_SUBPREFIX=		${GCC_PKGNAME}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${GCC_PREFIX}

CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}

INSTALLATION_DIRS+=	bin

post-extract:
	cd ${WRKDIR} && mv ${DISTNAME}/vhdl gcc-4.3.4/gcc

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -fs ../gcc43-ghdl/bin/ghdl .

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
