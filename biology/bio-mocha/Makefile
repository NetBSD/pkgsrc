# $NetBSD: Makefile,v 1.1 2024/10/11 22:44:39 bacon Exp $

DISTNAME=	bio-mocha-1.20
CATEGORIES=	biology
# Can't get ${MASTER_SITE_GITHUB:=samtools/} to work with additional distfile
MASTER_SITES=	https://software.broadinstitute.org/software/mocha/
MASTER_SITES+=	https://github.com/samtools/bcftools/releases/download/${GH_TAG}/
DISTFILES+=	bio-mocha_1.20-20240505.tar.gz
DISTFILES+=	bcftools-1.21.tar.bz2
GH_TAG=		1.21

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://software.broadinstitute.org/software/mocha/
COMMENT=	Bcftools plugin for mosaic chromosomal alteration analysis
LICENSE=	mit

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/usr/bin/env Rscript
REPLACE.R.new=		${PREFIX}/bin/Rscript
REPLACE_FILES.R=	MoCha/*.R

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[./version.sh 2>/dev/null\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	configure.ac

DEPENDS=	bash>=0:../../shells/bash
DEPENDS+=	bcftools>=1.16:../../biology/bcftools

USE_TOOLS+=	autoconf automake autoreconf bash gmake perl pax
GNU_CONFIGURE=	yes
REPLACE_PERL=	misc/* test/test.pl

WRKSRC=		${WRKDIR}/bcftools-${GH_TAG}

DATADIR=		${PREFIX}/share/bio-mocha
# FIXME: Why is share/bio-mocha only required on macOS?
INSTALLATION_DIRS=	libexec/bcftools share/bio-mocha

post-extract:
	${CP} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	${MKDIR} ${WRKSRC}/MoCha
	${CP} ${WRKDIR}/*.R ${WRKSRC}/MoCha

pre-configure:
	cd ${WRKSRC} && autoreconf -if

# One .so for each .c in the mocha distfile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/extendFMT.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mocha.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mochatools.so \
		${DESTDIR}${PREFIX}/libexec/bcftools
	(cd ${WRKSRC}/MoCha && pax -rw . ${DESTDIR}${DATADIR})

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
# Required for Linux, even though inherited from htslib
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
