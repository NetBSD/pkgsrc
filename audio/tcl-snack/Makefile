# $NetBSD: Makefile,v 1.1.1.1 2002/08/25 18:34:39 gson Exp $

DISTNAME=	snack2.2a2
PKGNAME=	tcl-snack-2.2a2
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/~kare/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gson@netbsd.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit

DEPENDS+=	tcl>=8.0:../../lang/tcl
GNU_CONFIGURE=	YES
USE_BUILDLINK_ONLY=	YES
WRKSRC=         ${WRKDIR}/${DISTNAME}/unix

.include "../../lang/tcl/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
