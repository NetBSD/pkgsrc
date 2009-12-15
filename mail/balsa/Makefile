# $NetBSD: Makefile,v 1.68 2009/12/15 21:54:17 joerg Exp $

DISTNAME=	balsa-2.3.26
PKGREVISION=	2
CATEGORIES=	mail gnome
MASTER_SITES=	http://balsa.gnome.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://balsa.gnome.org/
COMMENT=	GNOME2 EMail client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme:Q}/bin/gpgme-config
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=	--enable-smime
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-gtksourceview
CONFIGURE_ARGS+=	--with-gtkspell
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv_open=yes

EGDIR=		${PREFIX}/share/examples/balsa
CONF_FILES=	${EGDIR}/balsa.soundlist ${PKG_SYSCONFDIR}/sound/events/balsa.soundlist

.include "options.mk"

BUILDLINK_TRANSFORM+=		rm:-DGNOME_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGNOME_VFS_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGTK_DISABLE_DEPRECATED


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.1.9
.include "../../mail/gmime/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
