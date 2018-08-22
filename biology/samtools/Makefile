# $NetBSD: Makefile,v 1.2 2018/08/22 09:42:59 wiz Exp $

DISTNAME=	samtools-1.8
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.htslib.org/
COMMENT=	Tools for manipulating next-generation sequencing data
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf gmake perl:run
GNU_CONFIGURE=	yes
REPLACE_PERL=	misc/*.pl misc/plot-bamstats test/test.pl
REPLACE_PYTHON=	misc/*.py

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../biology/htslib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
