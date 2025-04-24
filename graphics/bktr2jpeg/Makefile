# $NetBSD: Makefile,v 1.15 2025/04/24 14:14:12 wiz Exp $
#

DISTNAME=	bktr2jpeg-1.0
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://core.de/~coto/projects/bktr2jpeg/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://core.de/~coto/projects/bktr2jpeg/
COMMENT=	Write jpeg image captured from /dev/bktr to file

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-*

MAKE_FLAGS+=		INSTALL=${INSTALL_PROGRAM:Q}
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
