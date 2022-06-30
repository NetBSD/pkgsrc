# $NetBSD: Makefile,v 1.7 2022/06/30 11:18:04 nia Exp $

DISTNAME=	peak-classifier-0.1.4
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/peak-classifier
COMMENT=	Classify ChIP/ATAC-Seq peaks based on features provided in a GFF
LICENSE=	2-clause-bsd

DEPENDS+=	bedtools>=0:../../biology/bedtools

REPLACE_PYTHON=	feature-view.py

pre-build:
	cd ${WRKSRC} && make depend PREFIX=${PREFIX}

.include "../../biology/biolibc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
