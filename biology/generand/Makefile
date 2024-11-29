# $NetBSD: Makefile,v 1.3 2024/11/29 13:59:36 bacon Exp $

DISTNAME=	generand-0.1.2.8
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	a715a8965d4cb44a9f195dc796c5c0fa871d1fd7

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/generand
COMMENT=	Generate random genomic data in FASTA/FASTQ, SAM, or VCF format
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../mk/bsd.pkg.mk"
