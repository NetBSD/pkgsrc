# $NetBSD: Makefile,v 1.3 2003/02/27 02:18:37 dmcmahill Exp $
#

DISTNAME=	latex-mk-1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://latex-mk.sourceforge.net
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

GNU_CONFIGURE=	YES

post-install:
	${RM} -fr ${PREFIX}/share/latex-mk/testsuite

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
