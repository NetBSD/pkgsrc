# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 05:00:46 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-fontserver-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R6.7.0-src1.tar.gz X11R6.7.0-src2.tar.gz \
		X11R6.7.0-src3.tar.gz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org font server

CONFLICTS=	XFree86-fontserver-[0-9]*

USE_X11=		yes
USE_BUILDLINK3=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans
XINSTALL_MAN_DIRS=	programs/xfs

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
