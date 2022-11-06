# $NetBSD: Makefile,v 1.1 2022/11/06 23:01:17 bacon Exp $

DISTNAME=	gffread-0.12.7
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=gpertea/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://ccb.jhu.edu/software/stringtie/gff.shtml
COMMENT=	GFF/GTF format conversions, filtering, FASTA extraction, etc
LICENSE=	mit

GITHUB_SUBMODULES=	gpertea gclib v0.12.7 gclib

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
INSTALL_TARGET=	install-strip

.include "../../mk/bsd.pkg.mk"
