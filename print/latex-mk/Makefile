# $NetBSD: Makefile,v 1.5 2003/06/14 14:21:43 dmcmahill Exp $
#

DISTNAME=	latex-mk-1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://latex-mk.sourceforge.net
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

GNU_CONFIGURE=	YES

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
