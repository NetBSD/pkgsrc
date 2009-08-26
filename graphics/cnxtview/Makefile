# $NetBSD: Makefile,v 1.12 2009/08/26 19:57:37 sno Exp $
#

DISTNAME=	cnxtutil-0.00-alpha
PKGNAME=	cnxtview-0.00a
PKGREVISION=	4
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.medias.ne.jp/~takam/bsd/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#webcamnote
COMMENT=	Creative WEBCAM Notebook Utility Programs

NOT_FOR_PLATFORM=	SunOS-*-*	# needs <err.h> and <dev/usb/usb.h>

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff
MAKE_ENV+=	NOGCCERROR=

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
