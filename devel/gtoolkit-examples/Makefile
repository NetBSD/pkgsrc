# $NetBSD: Makefile,v 1.4 2004/01/23 21:50:43 jmmv Exp $
#
.include "../../x11/gtoolkit/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-examples-/}
PKGREVISION=	3
CATEGORIES=	devel

COMMENT=	Objective-C examples for GToolKit

DISTINFO_FILE=	${.CURDIR}/../../x11/gtoolkit/distinfo
BUILD_DIRS=	${WRKSRC}/Examples

.include "../../x11/gtoolkit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
