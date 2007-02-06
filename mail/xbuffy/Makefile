# $NetBSD: Makefile,v 1.11 2007/02/06 18:30:26 joerg Exp $
#

DISTNAME=	xbuffy-3.4
PKGREVISION=	1
CATEGORIES=	mail x11
MASTER_SITES=	ftp://ftp.virginia.edu/pub/xbuffy/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replacement for xbiff that handles multiple mail files

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${X11BASE}/include
CPPFLAGS+=	-Wall

post-install:
	${INSTALL_DATA} ${WRKSRC}/XBuffy.ad ${PREFIX}/lib/X11/app-defaults/XBuffy

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
