# $NetBSD: Makefile,v 1.1.1.1 2002/11/09 05:22:28 rh Exp $
#
.include "../../x11/gtoolkit/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-examples-/}
CATEGORIES=	devel

COMMENT=	Objective-C examples for GToolKit

DISTINFO_FILE=	${.CURDIR}/../../x11/gtoolkit/distinfo
BUILD_DIRS=	${WRKSRC}/Examples

.include "../../x11/gtoolkit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
