# $NetBSD: Makefile,v 1.3 2003/10/05 13:13:06 cube Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
.include "../../graphics/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DESCR_SRC=	${.CURDIR}/../../graphics/nvtv/DESCR
DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
