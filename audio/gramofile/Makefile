# $NetBSD: Makefile,v 1.1.1.1 2004/07/04 22:35:40 agc Exp $
#

DISTNAME=	gramofile-1.6
CATEGORIES=	audio
MASTER_SITES=	http://panic.et.tudelft.nl/~costar/gramofile/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://panic.et.tudelft.nl/~costar/gramofile/
COMMENT=	Tool for ripping audio from vinyl

ALL_TARGET=	gramofile

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
