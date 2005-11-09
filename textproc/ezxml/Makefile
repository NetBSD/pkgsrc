# $NetBSD: Makefile,v 1.5 2005/11/09 22:49:45 wiz Exp $

DISTNAME=	ezxml-0.8.5
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ezxml/} \
		http://www.yazzy.org/pkgsrc/ezxml/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://ezxml.sourceforge.net/
COMMENT=	Easy to use C library for parsing XML documents

WRKSRC=		${WRKDIR}/ezxml

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS+=	lib include share/doc/ezxml

do-install:
	${INSTALL_DATA} ${WRKSRC}/libezxml.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/ezxml.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/ezxml.txt ${PREFIX}/share/doc/ezxml

.include "../../mk/bsd.pkg.mk"
