# $NetBSD: Makefile,v 1.90 2012/10/02 17:11:26 tron Exp $

DISTNAME=	balsa-2.4.8
PKGREVISION=	17
CATEGORIES=	mail gnome
MASTER_SITES=	http://pawsa.fedorapeople.org/balsa/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pawsa.fedorapeople.org/balsa/
COMMENT=	GNOME2 EMail client
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=	--enable-smime
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme}/bin/gpgme-config
CONFIGURE_ARGS+=	--with-gtksourceview
CONFIGURE_ARGS+=	--with-gtkspell
CONFIGURE_ARGS+=	--without-nm
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
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
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
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

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
