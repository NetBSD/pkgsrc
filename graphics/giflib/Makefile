# $NetBSD: Makefile,v 1.11 1998/07/24 01:57:00 tv Exp $
# FreeBSD Id: Makefile,v 1.2 1997/09/24 06:55:01 tg Exp
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/giflib/

MAINTAINER=	packages@netbsd.org

USE_LIBTOOL=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib

.include "../../mk/bsd.pkg.mk"
