# $NetBSD: Makefile,v 1.1 2023/01/23 21:38:50 bacon Exp $
#

DISTNAME=	atac-seq-1.1
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
COMMENT=	Core tools needed for ATAC-Seq analysis

DEPENDS+=	fastq-trim>=0:../../biology/fastq-trim
DEPENDS+=	fastqc>=0:../../biology/fastqc
DEPENDS+=	biolibc-tools>=0:../../biology/biolibc-tools
DEPENDS+=	gffread>=0:../../biology/gffread
DEPENDS+=	bwa>=0:../../biology/bwa
DEPENDS+=	bowtie2>=0:../../biology/bowtie2
DEPENDS+=	samtools>=0:../../biology/samtools
DEPENDS+=	igv>=0:../../biology/igv
DEPENDS+=	${PYPKGPREFIX}-macs2>=0:../../biology/py-macs2
DEPENDS+=	fasda>=0:../../biology/fasda
DEPENDS+=	peak-classifier>=0:../../biology/peak-classifier
DEPENDS+=	webbrowser>=0:../../www/webbrowser

META_PACKAGE=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
