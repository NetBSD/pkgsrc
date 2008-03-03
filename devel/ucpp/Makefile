# $NetBSD: Makefile,v 1.2 2008/03/03 17:45:38 jlam Exp $
#

DISTNAME=	ucpp-1.3
CATEGORIES=	devel
MASTER_SITES=	http://pornin.nerim.net/ucpp/

MAINTAINER=	asmodai@in-nomine.org
HOMEPAGE=	http://pornin.nerim.net/ucpp/
COMMENT=	C preprocessor and lexer

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ucpp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ucpp.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
