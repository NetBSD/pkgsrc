# $NetBSD: Makefile,v 1.4 2004/06/15 12:45:00 grant Exp $
#

DISTNAME=	bktr2jpeg-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://core.de/~coto/projects/bktr2jpeg/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://core.de/~coto/projects/bktr2jpeg/
COMMENT=	Write jpeg image captured from /dev/bktr to file

USE_BUILDLINK3=	YES

ONLY_FOR_PLATFORM=	NetBSD-*-*

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
