# $NetBSD: Makefile,v 1.1.1.1 2012/09/14 17:46:23 asau Exp $

DISTNAME=	plink-1.07-src
CATEGORIES=	biology
MASTER_SITES=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://pngu.mgh.harvard.edu/~purcell/plink/
COMMENT=	Whole-genome association analysis toolset
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	gmake

CXXFLAGS+=	-Dfopen64=fopen

MAKE_FLAGS+=	LIBDL=${DL_LIBS:Q}

LIB_LAPACK=	-L${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib -llapack -lblas -lf2c
MAKE_FLAGS+=	WITH_LAPACK=1 LIB_LAPACK=${LIB_LAPACK:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${DESTDIR}${PREFIX}/bin

do-test:
	cd $(WRKSRC) && ./plink --file test
	cd $(WRKSRC) && ./plink --file test --freq
	cd $(WRKSRC) && ./plink --file test --assoc
	cd $(WRKSRC) && ./plink --file test --make-bed

.include "../../devel/libf2c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
