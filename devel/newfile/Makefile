# $NetBSD: Makefile,v 1.4 2004/04/25 05:33:18 snj Exp $
#

DISTNAME=	newfile-1.0.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=newfile/}

MAINTAINER=	flynn@energyhq.homeip.net
HOMEPAGE=	http://newfile.sourceforge.net/
COMMENT=	Tool for creating starter files in various languages

DEPENDS+=	ruby-optparse>=0.8.6:../../devel/ruby-optparse

USE_RUBY=	YES
NO_BUILD=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

REPLACE_RUBY=	src/newfile.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/newfile.rb ${PREFIX}/bin/newfile
	${INSTALL_DATA} ${WRKSRC}/src/fileproc.rb ${WRKSRC}/src/sytab.rb \
		${PREFIX}/share/newfile/
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${PREFIX}/man/man1/

.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
