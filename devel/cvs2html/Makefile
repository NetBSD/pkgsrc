# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:45 jlam Exp $
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
