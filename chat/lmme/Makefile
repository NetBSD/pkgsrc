# $NetBSD: Makefile,v 1.3 2002/08/01 05:48:06 jlam Exp $
#

DISTNAME=	lmme-0.6.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmme/}

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://lmme.sourceforge.net/
COMMENT=	curses-based client for MSN Messenger chat system

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
PTHREAD_TYPE=		require
GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lmme ${PREFIX}/bin/lmme

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
