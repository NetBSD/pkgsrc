# $NetBSD: Makefile,v 1.24 2013/10/09 17:39:15 wiz Exp $

DISTNAME=	kmldonkey-0.11
PKGREVISION=	23
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_KDE:=apps/KDE3.x/network/}

MAINTAINER=	gallegos@csxxi.net.mx
HOMEPAGE=	http://www.kmldonkey.org/
COMMENT=	KDE3 Frontend for MLDonkey

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config gmake perl
GNU_CONFIGURE=	yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
