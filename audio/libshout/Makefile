# $NetBSD: Makefile,v 1.1.1.1 2004/01/12 03:56:19 kim Exp $
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
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PTHREAD_OPTS+=		require

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
