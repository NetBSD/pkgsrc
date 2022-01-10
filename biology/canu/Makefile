# $NetBSD: Makefile,v 1.15 2022/01/10 01:46:22 ryoon Exp $

DISTNAME=	canu-1.8
PKGREVISION=	12
CATEGORIES=	biology java
MASTER_SITES=	${MASTER_SITE_GITHUB:=marbl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://canu.readthedocs.io/
COMMENT=	Single molecule sequence assembler for genomes large and small
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnuplot>0:../../graphics/gnuplot

# Makefile compiles directly into ${DESTDIR}${PREFIX}
SUBST_CLASSES+=		optimize
SUBST_STAGE.optimize=	pre-configure
SUBST_SED.optimize+=	-e 's|-g3||g'
SUBST_SED.optimize+=	-e 's|-O3||g'
SUBST_SED.optimize+=	-e 's|-O4||g'
SUBST_SED.optimize+=	-e 's|-funroll-loops||g'
SUBST_SED.optimize+=	-e 's|-fexpensive-optimizations||g'
SUBST_SED.optimize+=	-e 's|-finline-functions||g'
SUBST_FILES.optimize+=	Makefile

SUBST_CLASSES+=		jar
SUBST_STAGE.jar=	pre-configure
SUBST_SED.jar+=		-e 's|\\$$bin/\.\./share/java/classes/mhap-|${PREFIX}/${JAVAJARDIR}/mhap-|g'
SUBST_FILES.jar+=	pipelines/canu/OverlapMhap.pm

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_SED.perl+=	-e 's|$$FindBin::RealBin/../lib/site_perl|${PREFIX}/${SITE_PERL_REL}|g'
SUBST_FILES.perl+=	pipelines/canu.pl

REPLACE_PERL+=		*.pl */*.pl

# May work on other 64-bit processors, but untested
ONLY_FOR_PLATFORM=	*-*-x86_64

USE_LANGUAGES=	c c++
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	gmake pax perl
GCC_REQD+=	4.8

WRKSRC=		${WRKDIR}/canu-${PKGVERSION_NOREV}/src
MAKE_ENV+=	DESTDIR=${WRKSRC}

TMP_INST=		${WRKSRC}${PREFIX}/${OPSYS}-${MACHINE_ARCH:S/x86_64/amd64/}
SITE_PERL_REL=		lib/perl5/site_perl
JAVAJARDIR=		share/java/classes
INSTALLATION_DIRS=	bin ${JAVAJARDIR}

post-extract:
	${CHMOD} -R g-w ${WRKDIR}/${DISTNAME}

post-build:
	${MKDIR} ${TMP_INST}/lib/perl5
	${MV} ${TMP_INST}/lib/site_perl ${TMP_INST}/lib/perl5
	${RM} -f ${TMP_INST}/bin/canu.defaults

do-install:
	cd ${TMP_INST}/bin && ${PAX} -wr * ${DESTDIR}${PREFIX}/bin
	cd ${TMP_INST}/lib/perl5 && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/perl5
	cd ${TMP_INST}/share && ${PAX} -wr * ${DESTDIR}${PREFIX}/share

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
