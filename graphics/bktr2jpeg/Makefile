# $NetBSD: Makefile,v 1.8 2007/01/08 03:27:27 rillig Exp $
#

DISTNAME=	bktr2jpeg-1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://core.de/~coto/projects/bktr2jpeg/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://core.de/~coto/projects/bktr2jpeg/
COMMENT=	Write jpeg image captured from /dev/bktr to file

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-*

MAKE_FLAGS+=	INSTALL=${INSTALL_PROGRAM:Q}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
