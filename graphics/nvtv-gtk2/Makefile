# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:36 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
PKGREVISION=	3
.include "../../graphics/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
