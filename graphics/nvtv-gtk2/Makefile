# $NetBSD: Makefile,v 1.2 2003/10/05 09:53:17 cube Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
.include "../../wip/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DESCR_SRC=	${.CURDIR}/../../graphics/nvtv/DESCR
DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
