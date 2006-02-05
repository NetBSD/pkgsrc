# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:06 joerg Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontserver-${XF_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	XFree86-${XF_VER}-src-1.tgz XFree86-${XF_VER}-src-2.tgz \
		XFree86-${XF_VER}-src-3.tgz XFree86-${XF_VER}-src-4.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 font server

DISTINFO_FILE=		${.CURDIR}/../../x11/XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/XFree86-libs/patches

XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans programs/Xserver
XINSTALL_MAN_DIRS=	programs/xfs

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
