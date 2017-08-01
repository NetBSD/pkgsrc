# $NetBSD: Makefile,v 1.21 2017/08/01 17:40:10 wiz Exp $
#

DISTNAME=	cvs2html-1.82
PKGREVISION=	5
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	Perl script to turn ``cvs log'' output into HTML

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	cvs2html

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
