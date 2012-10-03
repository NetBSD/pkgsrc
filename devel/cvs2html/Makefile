# $NetBSD: Makefile,v 1.15 2012/10/03 21:54:29 wiz Exp $
#

DISTNAME=	cvs2html-1.82
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvs.sslug.dk/cvs2html/
COMMENT=	Perl script to turn ``cvs log'' output into HTML

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	cvs2html

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2html ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
