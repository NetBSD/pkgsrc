# $NetBSD: Makefile,v 1.1.1.2 2003/10/05 09:19:29 cube Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
.include "../../wip/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DESCR_SRC=	${.CURDIR}/../../wip/nvtv/DESCR
DISTINFO_FILE=	${.CURDIR}/../../wip/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../wip/nvtv/files
PLIST_SRC=	${.CURDIR}/../../wip/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../wip/nvtv/patches

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
