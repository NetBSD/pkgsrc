# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:33 jlam Exp $
#

DISTNAME=	libshout-2.0
CATEGORIES=	audio
MASTER_SITES=	http://icecast.org/files/libshout/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.gnu.org/directory/audio/ogg/libshout.html
COMMENT=	Connects and sends data to icecast servers

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
