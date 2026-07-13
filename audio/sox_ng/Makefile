# $NetBSD: Makefile,v 1.3 2026/07/13 04:35:23 wiz Exp $

DISTNAME=	sox_ng-14.8.0.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://codeberg.org/sox_ng/sox_ng/releases/download/${DISTNAME}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/sox_ng/sox_ng
COMMENT=	SOund eXchange - universal sound sample translator
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# install compatibility links so this can replace 'sox'
CONFIGURE_ARGS+=	--enable-replace
CONFLICTS+=		sox-[0-9]*

PKGCONFIG_OVERRIDE+=	sox_ng.pc.in

TEST_TARGET=		check

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
