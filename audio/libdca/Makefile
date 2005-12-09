# $NetBSD: Makefile,v 1.1.1.1 2005/12/09 17:21:02 salo Exp $
#

DISTNAME=	libdts-0.0.2
PKGNAME=	${DISTNAME:S/ts/ca/}
CATEGORIES=	audio
MASTER_SITES=	http://debian.unnet.nl/pub/videolan/libdts/0.0.2/ \
		http://download.videolan.org/pub/videolan/libdts/0.0.2/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://developers.videolan.org/libdca.html
COMMENT=	Free DTS Coherent Acoustics decoder

RESTRICTED=	"Unresolved patent issue"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config

.include "../../mk/bsd.pkg.mk"
