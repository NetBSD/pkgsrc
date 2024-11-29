# $NetBSD: Makefile,v 1.10 2024/11/29 15:28:16 bacon Exp $

DISTNAME=	vcf-split-0.1.5.19
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	1a8ab827c0e08172d3c1309ea80436c690b94608

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/vcf-split
COMMENT=	Split a multi-sample VCF into single-sample VCFs
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
