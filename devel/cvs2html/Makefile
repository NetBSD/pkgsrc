# $NetBSD: Makefile,v 1.4 2001/11/30 17:30:12 jlam Exp $
#

DISTNAME=	cvs2html-1.82
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	perl script to turn ``cvs log'' output into HTML

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES
REPLACE_PERL=		cvs2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${PREFIX}/bin

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
