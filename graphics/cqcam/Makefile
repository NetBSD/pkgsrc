# $NetBSD: Makefile,v 1.19 2004/04/25 02:49:22 snj Exp $
#

DISTNAME=		cqcam-0.45a
CATEGORIES=    		graphics x11
MASTER_SITES=		http://www.cs.duke.edu/~reynolds/cqcam/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.duke.edu/~reynolds/cqcam/
COMMENT=		Free Color QuickCam control program

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-alpha

LICENSE=		no-profit

USE_BUILDLINK3=		YES
USE_X11=		YES

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
