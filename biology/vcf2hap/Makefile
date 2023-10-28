# $NetBSD: Makefile,v 1.8 2023/10/28 20:41:05 bacon Exp $

DISTNAME=	vcf2hap-0.1.6.7
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	2cc4a97bb3b08e1c336578b36af5970ce98c931a

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf2hap
COMMENT=	Generate .hap file from VCF for haplohseq
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
