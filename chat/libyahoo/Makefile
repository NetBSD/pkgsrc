# $NetBSD: Makefile,v 1.7 2004/10/03 00:13:15 tv Exp $

DISTNAME=	libyahoo-0.18.4
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libyahoo/}

MAINTAINER=	ken@246gt.com
HOMEPAGE=	http://sourceforge.net/projects/libyahoo/
COMMENT=	Yahoo! Messenger client library

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/libyahoo-authors.h ${PREFIX}/include/libyahoo

.include "../../mk/bsd.pkg.mk"
