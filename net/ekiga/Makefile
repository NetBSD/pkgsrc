# $NetBSD: Makefile,v 1.88 2018/11/14 22:22:09 kleink Exp $

DISTNAME=		ekiga-3.2.6
PKGREVISION=		66
CATEGORIES=		net comms
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ekiga/3.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.ekiga.org/
COMMENT=		VoIP and video conferencing application for GNOME
LICENSE=		gnu-gpl-v2

PREV_PKGPATH=		net/ekiga-devel

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-libsasl2-dir=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--enable-gstreamer

.include "options.mk"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++11
GCC_REQD+=		4.7

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# libsigc++ uses exceptions in the header files
BUILDLINK_TRANSFORM+=	rm:-fno-exceptions
.endif

.include "../../audio/esound/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/opal/buildlink3.mk"
.include "../../devel/ptlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
