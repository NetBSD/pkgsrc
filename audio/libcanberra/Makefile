# $NetBSD: Makefile,v 1.37 2014/05/05 00:47:37 ryoon Exp $

DISTNAME=	libcanberra-0.27
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libcanberra/
COMMENT=	Desktop event sound library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_lib_ltdl_lt_dladvise_init=yes

PKGCONFIG_OVERRIDE+=	libcanberra-gtk.pc.in
PKGCONFIG_OVERRIDE+=	libcanberra-gtk3.pc.in
PKGCONFIG_OVERRIDE+=	libcanberra.pc.in

REPLACE_SH=		src/libcanberra-logout-sound.sh.in

PLIST_VARS+=		oss

.include "options.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
PLIST.oss=	yes
.endif
.include "../../mk/bsd.pkg.mk"
