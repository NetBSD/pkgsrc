# $NetBSD: Makefile,v 1.27 2022/07/05 11:00:16 adam Exp $

DISTNAME=	htslib-1.15.1
CATEGORIES=	biology
# Github-generated distfiles are incomplete, use custom tarballs instead
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/htslib/releases/download/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

USE_TOOLS+=		autoconf automake autoreconf bash gmake perl
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[./version.sh 2>/dev/null\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	configure.ac

REPLACE_PERL+=		test/*.pl

CONFIGURE_ARGS+=	--enable-libcurl
PKGCONFIG_OVERRIDE=	htslib.pc.in
TEST_TARGET=		test
MAKE_ENV+=		BUILT_TEST_PROGRAMS=''

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
