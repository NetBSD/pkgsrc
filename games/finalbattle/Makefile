# $NetBSD: Makefile,v 1.12 2007/02/02 17:14:04 joerg Exp $
#

DISTNAME=	finalbattle.0.0
PKGNAME=	finalbattle-0.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/} \
		ftp://ftp.billsgames.com/unix/x/finalbattle/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://web.archive.org/web/2/http://www.newbreedsoftware.com/finalbattle/
COMMENT=	Multiplayer space battle simulation for X

WRKSRC=		${WRKDIR}/final
MAKE_FILE=	makefile

USE_X11BASE=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
