# $NetBSD: Makefile,v 1.3 2004/12/14 20:34:42 minskim Exp $

DISTNAME=	xvid4conf-1.12
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://zebra.fh-weingarten.de/~transcode/xvid4conf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://zebra.fh-weingarten.de/~transcode/
COMMENT=	XviD Configuration Panel
                                                                                
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=	YES

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
