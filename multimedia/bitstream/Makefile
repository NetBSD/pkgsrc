# $NetBSD: Makefile,v 1.2 2017/02/11 14:24:37 adam Exp $

DISTNAME=	bitstream-1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/bitstream/${PKGVERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/bitstream.html
COMMENT=	C headers allowing a simpler access to binary structures
LICENSE=	mit

USE_TOOLS+=	gmake
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
