# $NetBSD: Makefile,v 1.49 2007/04/15 11:05:03 wiz Exp $

DISTNAME=	gnomeicu-0.99.12
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
BROKEN_GETTEXT_DETECTION=	YES

CONFIGURE_ARGS+=	--sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/gnomeicu
CONF_FILES=		${EGDIR}/sound/events/GnomeICU.soundlist \
			${PKG_SYSCONFDIR}/sound/events/GnomeICU.soundlist

GCONF2_SCHEMAS=		gnomeicu.schemas

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
