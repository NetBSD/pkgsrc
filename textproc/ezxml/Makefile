# $NetBSD: Makefile,v 1.8 2012/10/25 06:55:50 asau Exp $

DISTNAME=	ezxml-0.8.5
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ezxml/}

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://ezxml.sourceforge.net/
COMMENT=	Easy to use C library for parsing XML documents

WRKSRC=		${WRKDIR}/ezxml

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS+=	lib include share/doc/ezxml

do-install:
	${INSTALL_DATA} ${WRKSRC}/libezxml.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/ezxml.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/ezxml.txt ${DESTDIR}${PREFIX}/share/doc/ezxml

.include "../../mk/bsd.pkg.mk"
