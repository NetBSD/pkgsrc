# $NetBSD: Makefile,v 1.6 2003/07/17 22:52:33 grant Exp $
#

DISTNAME=	latex-mk-1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

GNU_CONFIGURE=	YES

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
