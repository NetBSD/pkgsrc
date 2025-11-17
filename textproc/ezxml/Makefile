# $NetBSD: Makefile,v 1.13 2025/11/17 11:01:30 wiz Exp $

DISTNAME=	ezxml-0.8.6
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ezxml/}

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	https://ezxml.sourceforge.net/
COMMENT=	Easy to use C library for parsing XML documents

WRKSRC=		${WRKDIR}/ezxml

INSTALLATION_DIRS+=	lib include share/doc/ezxml

do-install:
	${INSTALL_DATA} ${WRKSRC}/libezxml.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/ezxml.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/ezxml.txt ${DESTDIR}${PREFIX}/share/doc/ezxml

.include "../../mk/bsd.pkg.mk"
