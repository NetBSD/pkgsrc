# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:19 tv Exp $
#

DISTNAME=	cvs2html-1.82
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	Perl script to turn ``cvs log'' output into HTML

NO_BUILD=	YES
USE_PERL5=	# defined
REPLACE_PERL=	cvs2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
