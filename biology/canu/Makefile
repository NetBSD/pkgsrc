# $NetBSD: Makefile,v 1.25 2024/02/23 14:30:58 bacon Exp $

DISTNAME=	canu-2.2
PKGREVISION=	3
CATEGORIES=	biology java
MASTER_SITES=	${MASTER_SITE_GITHUB:=marbl/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://canu.readthedocs.io/
COMMENT=	Single molecule sequence assembler for genomes large and small
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_SED.perl+=	-e 's|$$FindBin::RealBin/../lib/site_perl|${PREFIX}/${SITE_PERL_REL}|g'
SUBST_FILES.perl+=	pipelines/canu.pl

REPLACE_PERL+=	bogart/*.pl
REPLACE_PERL+=	pipelines/*.pl
REPLACE_PERL+=	bogus/*.pl
REPLACE_PERL+=	bogart-analysis/*.pl
REPLACE_PERL+=	overlapBasedTrimming/*.pl
REPLACE_PERL+=	overlapInCore-analysis/*.pl
REPLACE_PERL+=	merTrim/*.pl
REPLACE_PERL+=	erateEstimate/*.pl
REPLACE_PERL+=	meryl/.pl
REPLACE_PERL+=	fastq-utilities/*.pl
REPLACE_PERL+=	*.pl

# May work on other 64-bit processors, but untested
ONLY_FOR_PLATFORM=	*-*-x86_64 *-*-aarch64 *-*-powerpc64

USE_LANGUAGES=	c c++
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	gmake pax perl

WRKSRC=		${WRKDIR}/canu-${PKGVERSION_NOREV}/src
MAKE_ENV+=	DESTDIR=${WRKSRC}

TMP_INST=		${WRKSRC}/build
SITE_PERL_REL=		lib/perl5/site_perl
JAVAJARDIR=		share/java/classes
INSTALLATION_DIRS=	bin lib/perl5 ${JAVAJARDIR}

.include "../../mk/bsd.prefs.mk"

post-extract:
	${CHMOD} -R g-w ${WRKDIR}
.if ${MACHINE_ARCH} == "aarch64"
	${CP} ${FILESDIR}/cpuid_arm.c ${WRKSRC}/utility/src/parasail/cpuid.c
.elif ${MACHINE_ARCH} == "powerpc64"
	${CP} ${FILESDIR}/cpuid_ppc.c ${WRKSRC}/utility/src/parasail/cpuid.c
.endif

# Upstream does not want to use lib/perl5/site_perl
post-build:
	${MKDIR} ${TMP_INST}/lib/perl5
	${MV} ${TMP_INST}/lib/site_perl ${TMP_INST}/lib/perl5

do-install:
	cd ${TMP_INST}/bin && ${PAX} -wr * ${DESTDIR}${PREFIX}/bin
	cd ${TMP_INST}/lib/perl5 && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/perl5
	cd ${TMP_INST}/share && ${PAX} -wr * ${DESTDIR}${PREFIX}/share

# Xcode supports -Xpreprocessor -fopenmp, but does not supply OpenMP libs
# parallel/openmp installs an entire llvm
# Maybe a libomp package would suffice?
.if ${OPSYS} == Darwin
.include "../../parallel/openmp/buildlink3.mk"
.endif

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
