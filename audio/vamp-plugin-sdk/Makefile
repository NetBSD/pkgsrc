# $NetBSD: Makefile,v 1.5 2020/02/20 16:18:03 nia Exp $

DISTNAME=	vamp-plugin-sdk-2.9.0
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/2588/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vamp-plugins.org/
COMMENT=	The Vamp audio analysis plugin system
LICENSE=	x11

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# C++11
GCC_REQD+=	4.7

SUBST_CLASSES+=		dl
SUBST_STAGE.dl=		pre-configure
SUBST_MESSAGE.dl=	Fixing usage of -ldl in pkgconfig file.
SUBST_FILES.dl+=	pkgconfig/vamp-hostsdk.pc.in
SUBST_SED.dl=		-e "s,-ldl,${DL_LIBS},g"

PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=build/vamp-plugin.map

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
