# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:29 rh Exp $

DISTNAME=	gphoto-0.4.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gphoto.org/projects/gphoto/pub/tar/0.4/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/

DEPENDS+=	imlib-1.9.8:../../graphics/imlib

USE_X11BASE=		yes
USE_PKGLIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
