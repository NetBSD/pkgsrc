# $NetBSD: Makefile,v 1.6 2003/07/17 21:30:05 grant Exp $
#

DISTNAME=	cvs2html-1.82
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	perl script to turn ``cvs log'' output into HTML

USE_BUILDLINK2=	YES
NO_BUILD=	YES
REPLACE_PERL=	cvs2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${PREFIX}/bin

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
