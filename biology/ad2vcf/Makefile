# $NetBSD: Makefile,v 1.5 2022/03/15 21:08:32 bacon Exp $

DISTNAME=	ad2vcf-0.1.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

MAINTAINER=	bacon@NetBSD.org
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
