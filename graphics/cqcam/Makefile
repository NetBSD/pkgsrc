# $NetBSD: Makefile,v 1.18 2004/03/08 20:27:14 minskim Exp $
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

USE_BUILDLINK2=		YES
USE_X11=		YES

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
