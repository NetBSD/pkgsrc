# $NetBSD: Makefile,v 1.2 2019/07/26 15:31:08 nia Exp $

DISTNAME=	vamp-plugin-sdk-2.8.0
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/2450/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vamp-plugins.org/
COMMENT=	The Vamp audio analysis plugin system
LICENSE=	x11

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
