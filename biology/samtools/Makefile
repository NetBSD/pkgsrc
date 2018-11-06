# $NetBSD: Makefile,v 1.3 2018/11/06 10:49:41 adam Exp $

DISTNAME=	samtools-1.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.htslib.org/
COMMENT=	Tools for manipulating next-generation sequencing data
LICENSE=	mit

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-htslib=system
TEST_TARGET=		test

REPLACE_PERL=		misc/*.pl
REPLACE_PERL+=		misc/plot-bamstats
REPLACE_PERL+=		test/test.pl
REPLACE_PYTHON=		misc/*.py

.include "../../biology/htslib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
