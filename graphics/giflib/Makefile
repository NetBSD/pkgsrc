# $NetBSD: Makefile,v 1.10 1998/07/14 19:55:49 tv Exp $
# FreeBSD Id: Makefile,v 1.2 1997/09/24 06:55:01 tg Exp
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/giflib/

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

MAKE_ENV=	LIBTOOL=${PREFIX}/bin/libtool

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib

.include "../../mk/bsd.pkg.mk"
