# $NetBSD: Makefile,v 1.9 2023/10/28 20:39:31 bacon Exp $

DISTNAME=	vcf-split-0.1.5.10
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	0f2fd0a5051e058b82efd310679265bcda0b5b03

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
