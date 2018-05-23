# $NetBSD: Makefile,v 1.13 2018/05/23 17:45:23 adam Exp $

DISTNAME=	libdca-0.0.6
CATEGORIES=	audio
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdca/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/libdca.html
COMMENT=	DTS Coherent Acoustics decoder
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

RESTRICTED=		Unresolved patent issue
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

.include "../../mk/bsd.pkg.mk"
