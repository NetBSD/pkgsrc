# $NetBSD: Makefile,v 1.4 2003/10/06 12:55:36 cube Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
.include "../../graphics/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
