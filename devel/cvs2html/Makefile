# $NetBSD: Makefile,v 1.1.1.1 2001/06/24 13:30:17 zuntum Exp $
#

DISTNAME=	cvs2html-1.82
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	perl script to turn ``cvs log'' output into HTML

NO_BUILD=	YES
USE_PERL5=	YES

post-patch:
	${SED} "s,/usr/bin/perl,${PERL5}," ${WRKSRC}/cvs2html ${WRKSRC}/cvs2html.done
	${MV} ${WRKSRC}/cvs2html.done ${WRKSRC}/cvs2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
