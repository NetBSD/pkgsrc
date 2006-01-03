# $NetBSD: Makefile,v 1.14 2006/01/03 14:25:49 taca Exp $
#

DISTNAME=	newfile-1.0.14
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=newfile/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://newfile.sourceforge.net/
COMMENT=	Tool for creating starter files in various languages

NO_BUILD=	yes
GNU_CONFIGURE=	yes
REPLACE_RUBY=	src/newfile.rb.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/newfile.rb ${PREFIX}/bin/newfile
	${INSTALL_DATA} ${WRKSRC}/src/fileproc.rb ${WRKSRC}/src/sytab.rb \
		${PREFIX}/share/newfile/
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${PREFIX}/man/man1/

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
