# $NetBSD: Makefile,v 1.9 2003/07/21 16:34:32 martti Exp $
#

DISTNAME=	lmme-0.6.4
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmme/}

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://lmme.sourceforge.net/
COMMENT=	Curses-based client for MSN Messenger chat system

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
PTHREAD_TYPE=		require
GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lmme ${PREFIX}/bin/lmme

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
