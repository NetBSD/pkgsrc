# $NetBSD: Makefile,v 1.6 2019/07/01 04:07:57 ryoon Exp $

DISTNAME=	htslib-1.9
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libcurl
PKGCONFIG_OVERRIDE=	htslib.pc.in
TEST_TARGET=		test

REPLACE_PERL+=		test/compare_sam.pl
REPLACE_PERL+=		test/test.pl

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
