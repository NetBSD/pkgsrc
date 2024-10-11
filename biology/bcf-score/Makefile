# $NetBSD: Makefile,v 1.1 2024/10/11 22:49:06 bacon Exp $

DISTNAME=	bcf-score-1.20
CATEGORIES=	biology
# Can't get ${MASTER_SITE_GITHUB:=samtools/} to work with additional distfile
MASTER_SITES=	https://software.broadinstitute.org/software/score/
MASTER_SITES+=	https://github.com/samtools/bcftools/releases/download/${GH_TAG}/
DISTFILES+=	score_1.20-20240505.tar.gz
DISTFILES+=	bcftools-1.21.tar.bz2
GH_TAG=		1.21

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://software.broadinstitute.org/software/score/
COMMENT=	Bcftools plugin for mosaic chromosomal alteration analysis
LICENSE=	mit

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/usr/bin/env Rscript
REPLACE.R.new=		${PREFIX}/bin/Rscript
REPLACE_FILES.R=	bcf-score/*.R

REPLACE_BASH+=		mpileup_bench/compare_vcf_simple.sh

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[./version.sh 2>/dev/null\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	configure.ac

DEPENDS+=	bcftools>=1.16:../../biology/bcftools

USE_TOOLS+=	autoconf automake autoreconf bash gmake perl pax
GNU_CONFIGURE=	yes
REPLACE_PERL=	misc/* test/test.pl

WRKSRC=		${WRKDIR}/bcftools-${GH_TAG}

CFLAGS+=	-isystem ${PREFIX}/include/suitesparse
LDFLAGS+=	-lcholmod

DATADIR=		${PREFIX}/share/bcf-score
# FIXME: Why is share/bcf-score only necessary on darwin?
INSTALLATION_DIRS=	libexec/bcftools share/bcf-score

post-extract:
	${CP} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	${MKDIR} ${WRKSRC}/bcf-score
	${CP} ${WRKDIR}/*.R ${WRKSRC}/bcf-score

pre-configure:
	cd ${WRKSRC} && autoreconf -if

# One .so for each .c in the score distfile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/blup.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/liftover.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/metal.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/munge.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/pgs.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/score.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	(cd ${WRKSRC}/bcf-score && pax -rw . ${DESTDIR}${DATADIR})

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../math/suitesparse/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
# Needed on Linux, even though inherited from htslib
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
# Required by cholmod, a not-always-used component of suitesparse
.include "../../parallel/openmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
