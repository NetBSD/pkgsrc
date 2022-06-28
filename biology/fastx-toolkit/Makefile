# $NetBSD: Makefile,v 1.2 2022/06/28 11:31:00 wiz Exp $

DISTNAME=	fastx-toolkit-0.0.14.6
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=agordon/}
GITHUB_PROJECT=	fastx_toolkit
GITHUB_TAG=	ea0ca83ba24dce80c20ca589b838a281fe5deb0c

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/agordon/fastx_toolkit
COMMENT=	CLI tools for Short-Reads FASTA/FASTQ files preprocessing
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf bash pkg-config perl:run
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
REPLACE_PERL+=	scripts/*.pl
REPLACE_BASH+=	scripts/fastq_quality_boxplot_graph.sh
REPLACE_BASH+=	scripts/fastx_nucleotide_distribution_graph.sh
REPLACE_BASH+=	scripts/fastx_nucleotide_distribution_line_graph.sh

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -vif

.include "../../devel/libgtextutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
