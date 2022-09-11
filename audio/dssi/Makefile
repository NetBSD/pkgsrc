# $NetBSD: Makefile,v 1.4 2022/09/11 12:51:03 wiz Exp $

DISTNAME=	dssi-1.1.1
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dssi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dssi.sourceforge.net/
COMMENT=	API for audio processing plugins
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake gsed pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

PKGCONFIG_OVERRIDE+=	dssi.pc.in

.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
.  include "../../audio/libdssialsacompat/buildlink3.mk"
.endif
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
