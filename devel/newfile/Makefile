# $NetBSD: Makefile,v 1.2 2003/03/22 03:22:57 wiz Exp $
#

DISTNAME=	newfile-1.0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=newfile/}

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://newfile.sourceforge.net/
COMMENT=	Tool for creating starter files in various languages

DEPENDS+=	ruby-optparse>=0.8.6:../../devel/ruby-optparse

USE_RUBY=	YES
NO_BUILD=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

REPLACE_RUBY=	src/newfile.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/newfile.rb ${PREFIX}/bin/newfile
	${INSTALL_DATA} ${WRKSRC}/src/fileproc.rb ${WRKSRC}/src/sytab.rb \
		${PREFIX}/share/newfile/
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${PREFIX}/man/man1/

.include "../../lang/ruby-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
