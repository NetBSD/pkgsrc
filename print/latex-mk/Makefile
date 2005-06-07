# $NetBSD: Makefile,v 1.12 2005/06/07 17:32:58 jlam Exp $
#

DISTNAME=	latex-mk-1.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net/
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS=	awk echo env false find grep rm rmdir

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	BMAKE=${MAKE_PROGRAM:Q}

INFO_FILES=	latex-mk.info

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
