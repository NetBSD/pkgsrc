# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 10:20:04 uebayasi Exp $
#

DISTNAME=	lmme-0.6.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmme/}

MAINTAINER=	collver@linuxfreemail.com
HOMEPAGE=	http://lmme.sourceforge.net/
COMMENT=	curses-based client for MSN Messenger chat system

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CXXFLAGS+=		-Dselect=pth_select -Dsleep=pth_sleep -Dread=pth_read -Dwrite=pth_write

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lmme ${PREFIX}/bin/lmme

.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
