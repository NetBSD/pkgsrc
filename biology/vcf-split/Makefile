# $NetBSD: Makefile,v 1.6 2022/06/11 19:46:43 bacon Exp $

DISTNAME=	vcf-split-0.1.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
