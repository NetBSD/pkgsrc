# $NetBSD: Makefile,v 1.4 2012/09/12 00:24:43 asau Exp $
#

DISTNAME=	OpenSPC_snap-20050926
PKGNAME=	libopenspc-0.3.99.20050926
CATEGORIES=	audio
MASTER_SITES=	http://home.comcast.net/~brad.martin1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.comcast.net/~brad.martin1/
COMMENT=	Library and player for SPC sound files

WRKSRC=		${WRKDIR}/libopenspc-0.3.99
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
