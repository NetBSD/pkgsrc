# $NetBSD: Makefile,v 1.12 1998/08/20 15:17:00 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1997/09/24 06:55:01 tg Exp
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/giflib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ccil.org/~esr/giflib/

USE_LIBTOOL=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib

.include "../../mk/bsd.pkg.mk"
