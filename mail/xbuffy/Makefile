# $NetBSD: Makefile,v 1.6 2003/07/17 21:47:13 grant Exp $
#

DISTNAME=	xbuffy-3.4
CATEGORIES=	mail x11
MASTER_SITES=	ftp://ftp.virginia.edu/pub/xbuffy/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	replacement for xbiff that handles multiple mail files

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${X11BASE}/include
CPPFLAGS+=	-Wall

post-install:
	${INSTALL_DATA} ${WRKSRC}/XBuffy.ad ${PREFIX}/lib/X11/app-defaults/XBuffy

.include "../../mk/bsd.pkg.mk"
