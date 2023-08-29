# $NetBSD: Makefile,v 1.2 2023/08/29 21:49:56 bacon Exp $

DISTNAME=	STAR-2.7.10b
PKGNAME=	rna-star-2.7.10b
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexdobin/}
GITHUB_PROJECT=	STAR

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/alexdobin/STAR
COMMENT=	Spliced Transcripts Alignment to a Reference
LICENSE=	gnu-gpl-v3

SUBST_CLASSES+=		htslib
SUBST_STAGE.htslib=	pre-configure
SUBST_SED.htslib+=	-e 's|"htslib/htslib/sam.h"|<htslib/sam.h>|g'
SUBST_SED.htslib+=	-e 's|"htslib/htslib/kstring.h"|<htslib/kstring.h>|g'
SUBST_SED.htslib+=	-e 's|"htslib/htslib/bgzf.h"|<htslib/bgzf.h>|g'
SUBST_FILES.htslib+=	BAMfunctions.cpp
SUBST_FILES.htslib+=	IncludeDefine.h
SUBST_FILES.htslib+=	STAR.cpp
SUBST_FILES.htslib+=	bamRemoveDuplicates.cpp
SUBST_FILES.htslib+=	bam_cat.c
SUBST_FILES.htslib+=	bam_cat.h
SUBST_FILES.htslib+=	signalFromBAM.h

# May work on other 64-bit processors, but untested
ONLY_FOR_PLATFORM=	*-*-x86_64 *-*-aarch64 *-*-powerpc64

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAKE_FLAGS=	HTSLIB=''

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/STAR ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

# Xcode supports -Xpreprocessor -fopenmp, but does not supply OpenMP libs
# parallel/openmp installs an entire llvm
# Maybe a libomp package would suffice?
.if ${OPSYS} == Darwin
SUBST_CLASSES+=		openmp
SUBST_SED.openmp=	-e 's|-fopenmp|-Xpreprocessor &|g'
SUBST_STAGE.openmp=	pre-configure
SUBST_FILES.openmp=	Makefile
LDFLAGS+= 		-L${PREFIX}/lib -lomp -lm
.include "../../parallel/openmp/buildlink3.mk"
.endif

.include "../../biology/htslib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
