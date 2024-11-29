# $NetBSD: Makefile,v 1.4 2024/11/29 15:14:45 bacon Exp $

DISTNAME=	generand-0.1.2.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	502772efafca1212922bb6170d4de673df16ecb4

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/generand
COMMENT=	Generate random genomic data in FASTA/FASTQ, SAM, or VCF format
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../mk/bsd.pkg.mk"
