# $NetBSD: Makefile,v 1.4 2003/05/22 11:27:01 dmcmahill Exp $
#

DISTNAME=	latex-mk-1.0
PKGREVISION=	1
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
