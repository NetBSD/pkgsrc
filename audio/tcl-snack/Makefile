# $NetBSD: Makefile,v 1.13 2005/04/11 21:44:57 tv Exp $

DISTNAME=	snack2.2.8
PKGNAME=	tcl-snack-2.2.8
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/~kare/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=         ${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib

INSTALLATION_DIRS=	lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
