# $NetBSD: Makefile,v 1.13 2002/10/09 18:38:11 wiz Exp $
#

DISTNAME=		cqcam-0.45a
CATEGORIES=    		graphics x11
MASTER_SITES=		http://www.cs.duke.edu/~reynolds/cqcam/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.duke.edu/~reynolds/cqcam/
COMMENT=		Free Color QuickCam control program

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-alpha

LICENSE=		no-profit

USE_BUILDLINK2=		YES

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
