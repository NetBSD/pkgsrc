# $NetBSD: Makefile,v 1.9 2024/11/29 15:37:57 bacon Exp $

DISTNAME=	vcf2hap-0.1.6.14
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	8f3998572c360c74be44d47258659bbd00374286

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf2hap
COMMENT=	Generate .hap file from VCF for haplohseq
LICENSE=	2-clause-bsd

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
