# $NetBSD: Makefile,v 1.40 2005/06/26 18:45:43 jmmv Exp $

DISTNAME=	balsa-2.2.6
PKGREVISION=	2
CATEGORIES=	mail gnome
MASTER_SITES=	http://balsa.gnome.org/				\
		ftp://ftp.newton.cx/pub/balsa/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://balsa.gnome.org/
COMMENT=	GNOME2 EMail client

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_PERL5=		build
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS=		--with-gpgme=${BUILDLINK_PREFIX.gpgme}/bin/gpgme-config
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv_open=yes

EGDIR=		${PREFIX}/share/examples/balsa
.for cnf in balsa.soundlist email.soundlist
CONF_FILES+=	${EGDIR}/${cnf} ${PKG_SYSCONFDIR}/sound/events/${cnf}
.endfor

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

BUILDLINK_TRANSFORM+=		rm:-DGNOME_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGNOME_VFS_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGTK_DISABLE_DEPRECATED

BUILDLINK_DEPENDS.gmime+=	gmime>=2.1.9

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml36/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
