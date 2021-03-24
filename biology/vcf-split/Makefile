# $NetBSD: Makefile,v 1.1 2021/03/24 15:22:29 bacon Exp $

DISTNAME=	vcf-split-0.1.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
