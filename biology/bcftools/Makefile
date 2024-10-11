# $NetBSD: Makefile,v 1.19 2024/10/11 22:41:14 bacon Exp $

DISTNAME=	bcftools-1.21
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	Tools for manipulating BCF and VCF variant call files
LICENSE=	mit

USE_TOOLS+=		autoconf automake autoreconf bash gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-htslib=system
MAKE_ENV+=		USE_GPL=1
TEST_TARGET=		test

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[./version.sh 2>/dev/null\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	configure.ac

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_SED.bash+=	-e 's|/bin/bash|${TOOLS_PATH.bash}|'
SUBST_SED.bash+=	-e 's|\\/bin\\/bash|${TOOLS_PATH.bash:S,/,\\\/,g}|'
SUBST_FILES.bash=	test/test.pl

REPLACE_PERL+=		misc/*.pl
REPLACE_PERL+=		misc/fix-broken-GATK-Double-vs-Integer
REPLACE_PERL+=		misc/plot-vcfstats
REPLACE_PERL+=		test/test.pl
REPLACE_PYTHON+=	misc/*.py

pre-configure:
	cd ${WRKSRC} && autoreconf -if

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/color-chrs.pl \
		${DESTDIR}${PREFIX}/bin/color-chrs
	${MV} ${DESTDIR}${PREFIX}/bin/guess-ploidy.py\
	       ${DESTDIR}${PREFIX}/bin/guess-ploidy
	${MV} ${DESTDIR}${PREFIX}/bin/plot-roh.py \
		${DESTDIR}${PREFIX}/bin/plot-roh
	${MV} ${DESTDIR}${PREFIX}/bin/run-roh.pl \
		${DESTDIR}${PREFIX}/bin/run-roh
	${MV} ${DESTDIR}${PREFIX}/bin/vcfutils.pl \
		${DESTDIR}${PREFIX}/bin/vcfutils

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
