# $NetBSD: Makefile,v 1.8 1999/04/13 15:31:06 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/13 09:14:49 tg Exp
#

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibp.fr/pub/networking/

MAINTAINER=	packages@netbsd.org

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-install:
	@${MKDIR} ${PREFIX}/share/doc/bing
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bing

.include "../../mk/bsd.pkg.mk"
