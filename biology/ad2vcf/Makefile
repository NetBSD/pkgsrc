# $NetBSD: Makefile,v 1.2 2021/06/11 17:06:54 bacon Exp $

DISTNAME=	ad2vcf-0.1.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../devel/libxtend/buildlink3.mk"
.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
