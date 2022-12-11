# $NetBSD: Makefile,v 1.8 2022/12/11 21:16:46 bacon Exp $

DISTNAME=	peak-classifier-0.1.4.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	a5bcfecdda6e11c9bd24f8171e9162f86209af9d

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
