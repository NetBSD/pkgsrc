# $NetBSD: Makefile,v 1.8 2005/08/10 20:56:21 jlam Exp $

DISTNAME=	xvid4conf-1.12
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://zebra.fh-weingarten.de/~transcode/xvid4conf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://zebra.fh-weingarten.de/~transcode/
COMMENT=	XviD Configuration Panel

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
