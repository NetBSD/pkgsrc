# $NetBSD: Makefile,v 1.28 2016/04/20 12:10:32 nros Exp $

DISTNAME=	snack2.2.10
PKGNAME=	tcl-snack-2.2.10
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/snack/dist/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/snack/
COMMENT=	The Snack Sound Toolkit
LICENSE=	esdl-license AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib

INSTALLATION_DIRS=	lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
