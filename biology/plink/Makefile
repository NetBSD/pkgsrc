# $NetBSD: Makefile,v 1.11 2026/08/04 20:28:45 wiz Exp $

DISTNAME=	plink-1.07-src
PKGNAME=	${DISTNAME:-src=}
PKGREVISION=	1
CATEGORIES=	biology
#MASTER_SITES=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
EXTRACT_SUFX=	.zip

MAINTAINER=	bacon@NetBSD.org
#HOMEPAGE=	http://pngu.mgh.harvard.edu/~purcell/plink/
COMMENT=	Whole-genome association analysis toolset
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	gmake

SUBST_CLASSES.Darwin+=	crypt
SUBST_STAGE.crypt=	pre-build
SUBST_SED.crypt=	-e 's|-lcrypt||g'
SUBST_FILES.crypt=	Makefile

CXXFLAGS+=	-Dfopen64=fopen

MAKE_FLAGS+=	LIBDL=${DL_LIBS:Q}

LIB_LAPACK=	-L${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib -llapack -lblas -lf2c
MAKE_FLAGS+=	WITH_LAPACK=1 LIB_LAPACK=${LIB_LAPACK:Q}

MAKE_ENV.SunOS+=	LIB="-lsocket -lnsl"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${DESTDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC} && ./plink --file test
	cd ${WRKSRC} && ./plink --file test --freq
	cd ${WRKSRC} && ./plink --file test --assoc
	cd ${WRKSRC} && ./plink --file test --make-bed

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/libf2c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
