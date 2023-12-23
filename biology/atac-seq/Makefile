# $NetBSD: Makefile,v 1.8 2023/12/23 16:23:22 bacon Exp $
#

# Update minor version when adding or removing dependencies
# Update revision for all other changes
DISTNAME=	atac-seq-1.3
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools needed for ATAC-Seq analysis

DEPENDS+=	sra-tools>0:../../biology/sra-tools
DEPENDS+=	fastq-trim>0:../../biology/fastq-trim
DEPENDS+=	fastqc>0:../../biology/fastqc
DEPENDS+=	biolibc-tools>0:../../biology/biolibc-tools
DEPENDS+=	gffread>0:../../biology/gffread
DEPENDS+=	bwa>0:../../biology/bwa
DEPENDS+=	bowtie2>0:../../biology/bowtie2
DEPENDS+=	samtools>0:../../biology/samtools
DEPENDS+=	igv>0:../../biology/igv
DEPENDS+=	${PYPKGPREFIX}-macs2>0:../../biology/py-macs2
DEPENDS+=	fasda>0:../../biology/fasda
DEPENDS+=	peak-classifier>0:../../biology/peak-classifier
DEPENDS+=	${PYPKGPREFIX}-multiqc-[0-9]*:../../biology/py-multiqc
DEPENDS+=	webbrowser>0:../../www/webbrowser
DEPENDS+=	curl>0:../../www/curl
DEPENDS+=	lz4>0:../../archivers/lz4
DEPENDS+=	xz>0:../../archivers/xz
DEPENDS+=	zstd>0:../../archivers/zstd

META_PACKAGE=	yes

# Inherited from py-macs2 dep
PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
