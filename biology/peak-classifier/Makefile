# $NetBSD: Makefile,v 1.13 2023/10/28 20:37:17 bacon Exp $

DISTNAME=	peak-classifier-0.1.4.13
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	fb89af3b2e976c2ccb42d861324aa40591f5cadb

OWNER=		bacon@NetBSD.org
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
