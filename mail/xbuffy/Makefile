# $NetBSD: Makefile,v 1.4 2001/06/11 06:34:41 jlam Exp $
#

DISTNAME=	xbuffy-3.4
CATEGORIES=	mail x11
MASTER_SITES=	ftp://ftp.virginia.edu/pub/xbuffy/

MAINTAINER=	packages@netbsd.org
COMMENT=	replacement for xbiff that handles multiple mail files

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${X11BASE}/include
CPPFLAGS+=	-Wall

post-install:
	${INSTALL_DATA} ${WRKSRC}/XBuffy.ad ${PREFIX}/lib/X11/app-defaults/XBuffy

.include "../../mk/bsd.pkg.mk"
