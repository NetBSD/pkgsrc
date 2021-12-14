# $NetBSD: Makefile,v 1.4 2021/12/14 19:10:43 bacon Exp $

DISTNAME=	vcf-split-0.1.3.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	19713a4e0f739840335ced2e170b822398688146

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
