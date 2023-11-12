# $NetBSD: Makefile,v 1.21 2023/11/12 13:22:58 wiz Exp $
#

DISTNAME=	hwdecode-demos-0.9.6p1
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=gbeauchesne/}
GITHUB_TAG=	6b4c053b70b612f7375a3ccf6f27e62cd2bc5fea

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gbeauchesne/hwdecode-demos/
COMMENT=	Standalone programs showing off various HW acceleration APIs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake autoconf automake aclocal
USE_LIBTOOL=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoreconf -vif

PLIST_VARS+=	vdpau vaapi

.include "../../multimedia/libvdpau/buildlink3.mk"
.if ${VDPAU_AVAILABLE} == yes
PLIST.vdpau=	yes
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif
.include "../../multimedia/libva/buildlink3.mk"
.if ${VAAPI_AVAILABLE} == yes
PLIST.vaapi=	yes
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
