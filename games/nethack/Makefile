# $NetBSD: Makefile,v 1.6 1999/12/24 22:29:58 pooka Exp $

DISTNAME=	nethack-all-3.3.0
CATEGORIES=	games x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	root@garbled.net

DEPENDS+=	nethack-tty-3.3.0:../nethack-tty
DEPENDS+=	nethack-x11-3.3.0:../nethack-x11
#DEPENDS+=	nethack-qt-3.3.0:../nethack-qt

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
