# $NetBSD: Makefile,v 1.1 2022/12/12 18:39:36 bacon Exp $
#

DISTNAME=	rna-seq-1.0
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Core tools needed for RNA-Seq analysis

DEPENDS+=	fastq-trim>=0:../../biology/fastq-trim
DEPENDS+=	fastqc>=0:../../biology/fastqc
DEPENDS+=	biolibc-tools>=0:../../biology/biolibc-tools
DEPENDS+=	gffread>=0:../../biology/gffread
DEPENDS+=	kallisto>=0:../../biology/kallisto
DEPENDS+=	hisat2>=0:../../biology/hisat2
DEPENDS+=	samtools>=0:../../biology/samtools
DEPENDS+=	igv>=0:../../biology/igv
DEPENDS+=	fasda>=0:../../biology/fasda

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
