# $NetBSD: Makefile,v 1.1 2024/10/15 12:15:29 bacon Exp $
#
# Update minor version when adding/removing dependencies
# Update revision for lesser changes

DISTNAME=	mca-calling-0.1.0
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools for Mosaic Chromosomal Alteration event calling

DEPENDS+=	sra-tools>0:../../biology/sra-tools
DEPENDS+=	bcftools>0:../../biology/bcftools
DEPENDS+=	samtools>0:../../biology/samtools
DEPENDS+=	vcf-split>0:../../biology/vcf-split
DEPENDS+=	ad2vcf>0:../../biology/ad2vcf
DEPENDS+=	vcf2hap>0:../../biology/vcf2hap
DEPENDS+=	haplohseq>0:../../biology/haplohseq
DEPENDS+=	bio-mocha>0:../../biology/bio-mocha
DEPENDS+=	bedtools>0:../../biology/bedtools
DEPENDS+=	mawk>0:../../lang/mawk
DEPENDS+=	curl>0:../../www/curl
DEPENDS+=	lz4>0:../../archivers/lz4
DEPENDS+=	bzip2>0:../../archivers/bzip2
DEPENDS+=	xz>0:../../archivers/xz
DEPENDS+=	zstd>0:../../archivers/zstd

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
