# $NetBSD: Makefile,v 1.7 2009/12/15 21:30:52 joerg Exp $
#

DISTNAME=	libcanberra-0.22
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libcanberra/
COMMENT=	Desktop event sound library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
GCONF_SCHEMAS+=	libcanberra.schemas

PKGCONFIG_OVERRIDE+=	libcanberra-gtk.pc.in
PKGCONFIG_OVERRIDE+=	libcanberra.pc.in

SUBST_CLASSES+=		ltdlc
SUBST_SED.ltdlc=	-e "s,ltdlc,ltdl,"
SUBST_FILES.ltdlc=	configure
SUBST_MESSAGE.ltdlc=	Fixing libtool convenience library name.
SUBST_STAGE.ltdlc=	pre-configure

CONFIGURE_ENV+=	ac_cv_lib_ltdl_lt_dladvise_init=yes

#.include "../../devel/libltdl/convenience.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
