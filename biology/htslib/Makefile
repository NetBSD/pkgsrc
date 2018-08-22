# $NetBSD: Makefile,v 1.3 2018/08/22 09:42:59 wiz Exp $

DISTNAME=	htslib-1.8
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
GITHUB_PROJECT=	htslib
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf gmake perl
GNU_CONFIGURE=	yes
REPLACE_PERL=	test/compare_sam.pl test/test.pl

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[make print-version\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	${WRKSRC}/configure.ac

PKGCONFIG_OVERRIDE=	htslib.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
