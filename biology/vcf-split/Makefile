# $NetBSD: Makefile,v 1.7 2022/12/11 21:18:27 bacon Exp $

DISTNAME=	vcf-split-0.1.5.4
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	0a856b934cd483f5c10d93117aab6c7f887204e5

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
