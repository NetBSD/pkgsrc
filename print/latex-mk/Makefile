# $NetBSD: Makefile,v 1.28 2023/06/06 12:42:11 riastradh Exp $
#

DISTNAME=	latex-mk-2.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net/
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

LICENSE=	original-bsd

TOOL_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
TOOL_DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_TOOLS+=	awk echo env false find grep gzcat gzip makeinfo rm rmdir tar

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	BMAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ENV+=	GZCAT=${GZCAT:Q}
CONFIGURE_ENV+=	GZIP=${GZIP_CMD:Q}
MAKE_ENV+=	PDFTEX=${LOCALBASE}/bin/pdfetex

INFO_FILES=	yes

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
