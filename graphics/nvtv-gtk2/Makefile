# $NetBSD: Makefile,v 1.5 2003/12/13 00:45:24 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
PKGREVISION=	1
.include "../../graphics/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../graphics/nvtv/distinfo
FILESDIR=	${.CURDIR}/../../graphics/nvtv/files
PLIST_SRC=	${.CURDIR}/../../graphics/nvtv/PLIST
PATCHDIR=	${.CURDIR}/../../graphics/nvtv/patches

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
