# $NetBSD: Makefile,v 1.39 2014/01/01 11:52:29 wiz Exp $
#

DISTNAME=	gtk-vnc-0.5.2
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-vnc/0.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/gtk-vnc
COMMENT=	VNC viewer widget for GTK
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	gtk-vnc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk-vnc-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gvnc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gvncpulse-1.0.pc.in
PY_PATCHPLIST=	yes

CONFIGURE_ARGS+=	--with-coroutine=gthread

.include "options.mk"

# idea from arch linux PKGBUILD
CONFIGURE_SCRIPT=	../configure
CONFIGURE_DIRS=		gtk2-build gtk3-build
BUILD_DIRS=		gtk2-build gtk3-build
INSTALL_DIRS=		gtk2-build gtk3-build

pre-configure:
	${RM} -rf ${WRKSRC}/gtk2-build ${WRKSRC}/gtk3-build
	${MKDIR} ${WRKSRC}/gtk2-build ${WRKSRC}/gtk3-build

do-configure:
	cd ${WRKSRC}/gtk2-build \
	&& ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} \
	--with-gtk=2.0
	cd ${WRKSRC}/gtk3-build \
	&& ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} \
	--with-gtk=3.0

#VIEW_REQUIRED=0.6.0
#libview

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# libview is only used for an example which is not installed
#.include "../../devel/libview/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.4.0
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.18.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
