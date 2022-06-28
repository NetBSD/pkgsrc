# $NetBSD: Makefile,v 1.14 2022/06/28 11:30:59 wiz Exp $

DISTNAME=	bcftools-1.15
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	Tools for manipulating BCF and VCF variant call files
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf bash gmake perl
GNU_CONFIGURE=	yes

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

CONFIGURE_ARGS+=	--with-htslib=system
MAKE_ENV+=		USE_GPL=1
TEST_TARGET=		test

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

.include "../../biology/htslib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
