# $NetBSD: Makefile,v 1.5 2002/12/01 21:57:06 gson Exp $

DISTNAME=	snack2.2
PKGNAME=	tcl-snack-2.2
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/~kare/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gson@netbsd.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES
WRKSRC=         ${WRKDIR}/${DISTNAME}/unix

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
