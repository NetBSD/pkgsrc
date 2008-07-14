# $NetBSD: Makefile,v 1.7 2008/07/14 12:55:56 joerg Exp $
#

DISTNAME=	libdts-0.0.2
PKGNAME=	${DISTNAME:S/ts/ca/}
CATEGORIES=	audio
MASTER_SITES=	http://debian.unnet.nl/pub/videolan/libdts/0.0.2/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://developers.videolan.org/libdca.html
COMMENT=	Free DTS Coherent Acoustics decoder

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	Unresolved patent issue
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.pkg.mk"
