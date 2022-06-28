# $NetBSD: Makefile,v 1.9 2022/06/28 11:31:01 wiz Exp $

DISTNAME=	stacks-2.60
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://catchenlab.life.illinois.edu/stacks/
COMMENT=	Software pipeline for building loci from short-read sequences
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++14
USE_TOOLS+=	bash perl:run
GNU_CONFIGURE=	yes

REPLACE_BASH+=		scripts/stacks-count-reads-per-sample-per-locus
REPLACE_BASH+=		scripts/stacks-dist-extract
REPLACE_BASH+=		scripts/stacks-gdb
REPLACE_BASH+=		scripts/stacks-samtools-tview
REPLACE_PERL=		scripts/*.pl
REPLACE_PYTHON+=	scripts/*.py
REPLACE_PYTHON+=	scripts/stacks-integrate-alignments

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	scripts/stacks-hist2d-loci-samples-coverage

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
# pkgsrc sed wrapper lacks -i
SUBST_CLASSES+=		sed
SUBST_STAGE.sed=	pre-configure
SUBST_FILES.sed=	Makefile.in
SUBST_SED.sed=		-e 's|sed -i.bkp|/usr/bin/sed -i .bkp|'
.else
# macOS clang lacks OpenMP
CFLAGS+=		-fopenmp
.endif

LDFLAGS.SunOS+=		-lsocket

.include "../../lang/python/application.mk"
.include "../../math/R/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
