# $NetBSD: Makefile,v 1.16 2010/01/29 23:10:38 joerg Exp $
#

DISTNAME=	icbm3d.0.4
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/icbm3d/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/icbm3d/
COMMENT=	3D X11 game of defense

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin

WRKSRC=		${WRKDIR}/icbm3d
MAKE_FILE=	makefile

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
