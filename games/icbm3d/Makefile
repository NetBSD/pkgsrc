# $NetBSD: Makefile,v 1.14 2007/02/02 18:47:08 joerg Exp $
#

DISTNAME=	icbm3d.0.4
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/icbm3d/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/icbm3d/
COMMENT=	3D X11 game of defense

WRKSRC=		${WRKDIR}/icbm3d
MAKE_FILE=	makefile

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
