# $NetBSD: Makefile,v 1.4 2008/12/08 11:03:48 obache Exp $
#

DISTNAME=	ucpp-1.3
CATEGORIES=	devel
#MASTER_SITES=	http://ucpp.googlecode.com/files/

MAINTAINER=	asmodai@in-nomine.org
HOMEPAGE=	http://code.google.com/p/ucpp/
COMMENT=	C preprocessor and lexer

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucpp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ucpp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
