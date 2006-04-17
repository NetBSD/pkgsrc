# $NetBSD: Makefile,v 1.11 2006/04/17 13:46:20 wiz Exp $
#
.include "../../x11/gtoolkit/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-examples-/}
PKGREVISION=	8
CATEGORIES=	devel

COMMENT=	Objective-C examples for GToolKit

DISTINFO_FILE=	${.CURDIR}/../../x11/gtoolkit/distinfo
PATCHDIR=	${.CURDIR}/../../x11/gtoolkit/patches
BUILD_DIRS=	${WRKSRC}/Examples

.include "../../x11/gtoolkit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
