# $NetBSD: Makefile,v 1.3 2002/08/26 02:26:26 gson Exp $

DISTNAME=	snack2.2a2
PKGNAME=	tcl-snack-2.2a2
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/~kare/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	gson@netbsd.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit

DEPENDS+=	tcl>=8.0:../../lang/tcl
DEPENDS+=	tk>=8.0:../../x11/tk

GNU_CONFIGURE=	YES
WRKSRC=         ${WRKDIR}/${DISTNAME}/unix

.include "../../mk/bsd.pkg.mk"
