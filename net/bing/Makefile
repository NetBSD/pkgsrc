# $NetBSD: Makefile,v 1.11 2003/01/19 07:29:41 salo Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/13 09:14:49 tg Exp
#

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibp.fr/pub/networking/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cnam.fr/reseau/bing.html
COMMENT=	Bing is a point-to-point bandwith measurement tool

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bing
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bing

.include "../../mk/bsd.pkg.mk"
