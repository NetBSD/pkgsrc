# $NetBSD: Makefile,v 1.2 2004/01/24 09:15:19 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontserver-${XF_VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-2.tgz \
		X430src-3.tgz X430src-4.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 font server

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/../../x11/XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/XFree86-libs/patches

XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver programs/xfs

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../x11/XFree86-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
