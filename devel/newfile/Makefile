# $NetBSD: Makefile,v 1.13.2.1 2006/02/05 23:15:42 salo Exp $
#

DISTNAME=	newfile-1.0.14
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=newfile/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://newfile.sourceforge.net/
COMMENT=	Tool for creating starter files in various languages

NO_BUILD=	yes
GNU_CONFIGURE=	yes
USE_RUBY_DIST_SUBDIR=	yes
REPLACE_RUBY=	src/newfile.rb.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/newfile.rb ${PREFIX}/bin/newfile
	${INSTALL_DATA} ${WRKSRC}/src/fileproc.rb ${WRKSRC}/src/sytab.rb \
		${PREFIX}/share/newfile/
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${PREFIX}/man/man1/

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
