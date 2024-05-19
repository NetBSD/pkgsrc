# $NetBSD: Makefile,v 1.8 2024/05/19 12:56:54 bacon Exp $

DISTNAME=	ad2vcf-0.1.6.19
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	f42ae919986d35de2ed6868c22712519d1d0f067

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION}

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
