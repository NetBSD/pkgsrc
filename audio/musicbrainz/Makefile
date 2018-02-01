# $NetBSD: Makefile,v 1.28 2018/02/01 10:04:38 jperkin Exp $

DISTNAME=	libmusicbrainz-2.1.5
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libmusicbrainz
COMMENT=	Second generation incarnation of the CD Index (2.x series)
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libmusicbrainz.pc.in

CONFIGURE_ARGS+=	--enable-cpp-headers

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
