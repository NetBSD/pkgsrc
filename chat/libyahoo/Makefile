# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:34 jlam Exp $

DISTNAME=	libyahoo-0.18.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libyahoo/}

MAINTAINER=	ken@246gt.com
HOMEPAGE=	http://sourceforge.net/projects/libyahoo/
COMMENT=	Yahoo! Messenger client library

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

post-install:
	${INSTALL_DATA} ${WRKSRC}/libyahoo-authors.h ${PREFIX}/include/libyahoo

.include "../../mk/bsd.pkg.mk"
