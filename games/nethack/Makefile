# $NetBSD: Makefile,v 1.5 1999/09/28 20:40:03 soren Exp $

DISTNAME=	nethack-all-3.2.2
CATEGORIES=	games x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	root@garbled.net

DEPENDS+=	nethack-tty-3.2.2:../nethack-tty
DEPENDS+=	nethack-x11-3.2.2:../nethack-x11
DEPENDS+=	nethack-qt-3.2.2:../nethack-qt

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
