# $NetBSD: Makefile,v 1.9 2001/02/17 18:18:37 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/13 09:14:49 tg Exp
#

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibp.fr/pub/networking/

MAINTAINER=	packages@netbsd.org
COMMENT=	Bing is a point-to-point bandwith measurement tool

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-install:
	@${MKDIR} ${PREFIX}/share/doc/bing
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bing

.include "../../mk/bsd.pkg.mk"
