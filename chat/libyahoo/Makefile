# $NetBSD: Makefile,v 1.2 2001/10/23 01:43:09 jlam Exp $

DISTNAME=	libyahoo-0.18.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libyahoo/}

MAINTAINER=	ken@246gt.com
HOMEPAGE=	http://sourceforge.net/projects/libyahoo/
COMMENT=	Yahoo! Messenger client library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

post-install:
	cd ${WRKSRC}; for file in libyahoo-authors.h; do		\
		${INSTALL_DATA} $${file} ${PREFIX}/include/libyahoo/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
