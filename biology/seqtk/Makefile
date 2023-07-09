# $NetBSD: Makefile,v 1.2 2023/07/09 08:41:40 nia Exp $

DISTNAME=	seqtk-1.4
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/lh3/seqtk
COMMENT=	Tool for processing sequences in FASTA/FASTQ format
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
