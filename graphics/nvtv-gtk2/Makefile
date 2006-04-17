# $NetBSD: Makefile,v 1.11 2006/04/17 13:46:33 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
PKGREVISION=	4
.include "../../graphics/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
