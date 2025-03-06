# $NetBSD: Makefile,v 1.11 2025/03/06 01:19:05 bacon Exp $

DISTNAME=	vcf-split-0.1.5.19
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	1a8ab827c0e08172d3c1309ea80436c690b94608

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
