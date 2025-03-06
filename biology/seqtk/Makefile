# $NetBSD: Makefile,v 1.3 2025/03/06 01:19:05 bacon Exp $

DISTNAME=	seqtk-1.4
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/lh3/seqtk
COMMENT=	Tool for processing sequences in FASTA/FASTQ format
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
