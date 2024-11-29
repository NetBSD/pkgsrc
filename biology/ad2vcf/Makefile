# $NetBSD: Makefile,v 1.9 2024/11/29 12:54:12 bacon Exp $

DISTNAME=	ad2vcf-0.1.6.20
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	51c419e6c5b55e3973f1a9229dc5a95a4f1a8919

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/ad2vcf
COMMENT=	Add allelic depth info from a SAM stream to a VCF file
LICENSE=	2-clause-bsd

MAKE_ENV+=	VERSION=${PKGVERSION} MANDIR=${PREFIX}/${PKGMANDIR}

do-test:
	cd ${WRKSRC}/Test && ./run-test.sh

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
