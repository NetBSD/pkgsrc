# $NetBSD: Makefile,v 1.6 2004/03/28 22:06:15 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontserver-${XF_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	XFree86-4.4.0-src-1.tgz XFree86-4.4.0-src-2.tgz \
		XFree86-4.4.0-src-3.tgz XFree86-4.4.0-src-4.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 font server

USE_X11=		yes
USE_BUILDLINK3=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/XFree86-libs/patches

XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans programs/Xserver
XINSTALL_MAN_DIRS=	programs/xfs

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
