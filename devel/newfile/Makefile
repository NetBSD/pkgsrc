# $NetBSD: Makefile,v 1.9 2005/01/28 14:19:35 taca Exp $
#

DISTNAME=	newfile-1.0.14
CATEGORIES=	devel
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=newfile/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://newfile.sourceforge.net/
COMMENT=	Tool for creating starter files in various languages

USE_BUILDLINK3=	yes
NO_BUILD=	yes
GNU_CONFIGURE=	yes

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "16"
DEPENDS+=	${RUBY_PKGPREFIX}-optparse>=0.8.6:../../devel/ruby-optparse
.endif

REPLACE_RUBY=	src/newfile.rb.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/newfile.rb ${PREFIX}/bin/newfile
	${INSTALL_DATA} ${WRKSRC}/src/fileproc.rb ${WRKSRC}/src/sytab.rb \
		${PREFIX}/share/newfile/
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${PREFIX}/man/man1/

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
