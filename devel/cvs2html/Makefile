# $NetBSD: Makefile,v 1.3 2001/06/27 11:44:26 zuntum Exp $
#

DISTNAME=	cvs2html-1.82
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	perl script to turn ``cvs log'' output into HTML

NO_BUILD=	YES
USE_PERL5=	YES
REPLACE_PERL=	cvs2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
