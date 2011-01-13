# $NetBSD: Makefile,v 1.17 2011/01/13 13:37:57 wiz Exp $
#

DISTNAME=	cnxtutil-0.00-alpha
PKGNAME=	cnxtview-0.00a
PKGREVISION=	7
CATEGORIES=	graphics x11
MASTER_SITES=	http://home.384.jp/takam/bsd/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://home.384.jp/takam/bsd/NetBSD.html#webcamnote
COMMENT=	Creative WEBCAM Notebook Utility Programs

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	SunOS-*-*	# needs <err.h> and <dev/usb/usb.h>

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff
MAKE_ENV+=	NOGCCERROR=

INSTALLATION_DIRS+=	bin

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
