# $NetBSD: Makefile,v 1.21 2004/10/03 00:14:49 tv Exp $
#

DISTNAME=		cqcam-0.45a
PKGREVISION=	1
CATEGORIES=    		graphics x11
MASTER_SITES=		http://www.cs.duke.edu/~reynolds/cqcam/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.duke.edu/~reynolds/cqcam/
COMMENT=		Free Color QuickCam control program

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-alpha

LICENSE=		no-profit

USE_BUILDLINK3=		YES
USE_LANGUAGES=		c c++
USE_X11=		YES

post-install:
	${RM} ${PREFIX}/man/man1/webcam.1.gz
	${RM} ${PREFIX}/man/man1/xcqcam.1.gz
	${LN} ${PREFIX}/man/man1/cqcam.1 ${PREFIX}/man/man1/webcam.1
	${LN} ${PREFIX}/man/man1/cqcam.1 ${PREFIX}/man/man1/xcqcam.1

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
