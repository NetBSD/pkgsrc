# $NetBSD: Makefile,v 1.11 2002/09/13 05:16:45 jlam Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	4
COMMENT=	Aladdin Postscript interpreter

USE_X11=		YES
MAKEFRAGS+=		${FILESDIR}/devs.x11
GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../ghostscript-nox11/Makefile.common"
