# $NetBSD: Makefile,v 1.30 2020/06/05 12:49:07 jperkin Exp $

DISTNAME=	cnxtutil-0.00-alpha
PKGNAME=	cnxtview-0.00a
PKGREVISION=	17
CATEGORIES=	graphics x11
MASTER_SITES=	http://home.384.jp/takam/bsd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.384.jp/takam/bsd/NetBSD.html#webcamnote
COMMENT=	Creative WEBCAM Notebook Utility Programs

NOT_FOR_PLATFORM=	SunOS-*-*	# needs <err.h> and <dev/usb/usb.h>

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff
MAKE_ENV+=		NOGCCERROR=

INSTALLATION_DIRS+=	bin

.include "../../graphics/imlib-gtk/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
