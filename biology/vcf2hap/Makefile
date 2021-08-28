# $NetBSD: Makefile,v 1.3 2021/08/28 18:40:06 bacon Exp $

DISTNAME=	vcf2hap-0.1.3.12
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	3626f5a320be8176d359b487682385fa6ab0f197

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf2hap
COMMENT=	Generate .hap file from VCF for haplohseq
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../devel/libxtend/buildlink3.mk"
.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
