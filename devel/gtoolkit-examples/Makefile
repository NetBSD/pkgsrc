# $NetBSD: Makefile,v 1.7 2004/05/13 13:10:19 wiz Exp $
#
.include "../../x11/gtoolkit/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-examples-/}
PKGREVISION=	4
CATEGORIES=	devel

COMMENT=	Objective-C examples for GToolKit

DISTINFO_FILE=	${.CURDIR}/../../x11/gtoolkit/distinfo
PATCHDIR=	${.CURDIR}/../../x11/gtoolkit/patches
BUILD_DIRS=	${WRKSRC}/Examples

.include "../../x11/gtoolkit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
