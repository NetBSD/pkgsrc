# $NetBSD: Makefile,v 1.9 2006/02/12 15:29:18 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-fontserver-${XORG_VER}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R${XORG_VER}-src1.tar.gz X11R${XORG_VER}-src2.tar.gz \
		X11R${XORG_VER}-src3.tar.gz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org font server

DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		programs/xfs
XINCLUDE_DIRS=		lib/xtrans
XINSTALL_MAN_DIRS=	programs/xfs

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
