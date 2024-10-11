# $NetBSD: Makefile,v 1.38 2024/10/11 22:36:15 bacon Exp $

# CAUTION: htslib should always be upgraded in conjunction with
# samtools, bcftools, bio-mocha, and bcf-score
DISTNAME=	htslib-1.21
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

USE_TOOLS+=		autoconf automake autoreconf bash:test gmake perl:test
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libcurl
PKGCONFIG_OVERRIDE=	htslib.pc.in
TEST_TARGET=		test
MAKE_ENV+=		BUILT_TEST_PROGRAMS=''

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[./version.sh 2>/dev/null\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	configure.ac

REPLACE_PERL+=		test/*.pl

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libdeflate/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
