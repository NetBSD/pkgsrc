# $NetBSD: Makefile,v 1.7 2003/07/17 21:23:28 grant Exp $

DISTNAME=	snack2.2
PKGNAME=	tcl-snack-2.2
WRKSRC=         ${WRKDIR}/${DISTNAME}/unix
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/~kare/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
