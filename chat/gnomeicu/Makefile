# $NetBSD: Makefile,v 1.80 2012/07/15 08:22:47 wiz Exp $

DISTNAME=	gnomeicu-0.99.12
PKGREVISION=	26
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
BROKEN_GETTEXT_DETECTION=	YES

LIBS.SunOS+=		-lsocket

CONFIGURE_ARGS+=	--sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/gnomeicu
CONF_FILES=		${EGDIR}/sound/events/GnomeICU.soundlist \
			${PKG_SYSCONFDIR}/sound/events/GnomeICU.soundlist

GCONF_SCHEMAS=		gnomeicu.schemas

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
