# $NetBSD: Makefile,v 1.1 2018/11/15 09:21:24 adam Exp $

DISTNAME=	bcftools-1.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samtools.github.io/bcftools/
COMMENT=	Calling and manipulating files VCF and BCF formats
LICENSE=	mit

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-htslib=system
TEST_TARGET=		test

BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

REPLACE_PERL+=		misc/*.pl
REPLACE_PERL+=		misc/plot-vcfstats
REPLACE_PYTHON+=	misc/*.py

.include "../../biology/htslib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
