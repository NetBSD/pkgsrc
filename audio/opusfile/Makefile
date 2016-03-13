# $NetBSD: Makefile,v 1.6 2016/03/13 08:04:06 tnn Exp $

DISTNAME=	opusfile-0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opus-codec.org/
COMMENT=	Decoding and seeking API for opus files
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	opusfile.pc.in
PKGCONFIG_OVERRIDE+=	opusurl.pc.in

CONFIGURE_ARGS+=	--disable-doc	# needs doxygen

.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
