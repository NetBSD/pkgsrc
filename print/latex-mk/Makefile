# $NetBSD: Makefile,v 1.7 2003/08/04 21:43:43 seb Exp $
#

DISTNAME=	latex-mk-1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

GNU_CONFIGURE=	YES

USE_NEW_TEXINFO=	YES
INFO_FILES=	latex-mk.info

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
