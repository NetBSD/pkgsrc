# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:02 wiz Exp $
#
.include "../../x11/gtoolkit/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-examples-/}
PKGREVISION=	6
CATEGORIES=	devel

COMMENT=	Objective-C examples for GToolKit

DISTINFO_FILE=	${.CURDIR}/../../x11/gtoolkit/distinfo
PATCHDIR=	${.CURDIR}/../../x11/gtoolkit/patches
BUILD_DIRS=	${WRKSRC}/Examples

.include "../../x11/gtoolkit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
