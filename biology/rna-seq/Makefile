# $NetBSD: Makefile,v 1.5 2023/07/23 02:10:54 wiz Exp $

DISTNAME=	rna-seq-1.2
CATEGORIES=	biology meta-pkgs
MASTER_SITES=	# empty

OWNER=		bacon@NetBSD.org
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
DEPENDS+=	webbrowser>=0:../../www/webbrowser
DEPENDS+=	${PYPKGPREFIX}-multiqc-[0-9]*:../../biology/py-multiqc

META_PACKAGE=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
