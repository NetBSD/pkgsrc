# $NetBSD: Makefile,v 1.24 2021/05/21 16:40:02 nia Exp $
#

DISTNAME=	newfile-1.0.14
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=newfile/}

MAINTAINER=	flynn@energyhq.es.eu.org
HOMEPAGE=	http://newfile.sourceforge.net/
COMMENT=	Tool for creating starter files in various languages
LICENSE=	modified-bsd

NO_BUILD=	yes
GNU_CONFIGURE=	yes
REPLACE_RUBY=	src/newfile.rb.in
USE_TOOLS+=	ksh

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/newfile.rb ${DESTDIR}${PREFIX}/bin/newfile
	${INSTALL_DATA} ${WRKSRC}/src/fileproc.rb ${WRKSRC}/src/sytab.rb \
	    ${DESTDIR}${PREFIX}/share/newfile/
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
