# $NetBSD: Makefile,v 1.9 2004/03/08 20:27:13 minskim Exp $

DISTNAME=	snack2.2
PKGNAME=	tcl-snack-2.2
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/~kare/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit

WRKSRC=         ${WRKDIR}/${DISTNAME}/unix
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
