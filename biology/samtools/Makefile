# $NetBSD: Makefile,v 1.6 2019/08/11 13:18:01 wiz Exp $

DISTNAME=	samtools-1.9
PKGREVISION=	2
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

.include "../../devel/zlib/buildlink3.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
