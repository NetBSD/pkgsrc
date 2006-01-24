# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:16 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
PKGREVISION=	2
.include "../../graphics/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
