# $NetBSD: Makefile,v 1.12 2003/02/23 00:57:52 itohy Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	4
COMMENT=	Aladdin Postscript interpreter

USE_X11=		YES
GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
