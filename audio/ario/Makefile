# $NetBSD: Makefile,v 1.105 2022/06/28 11:30:53 wiz Exp $

DISTNAME=	ario-1.6
PKGREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ario-player/1.6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ario-player.sourceforge.net/
COMMENT=	Graphical client for mpd using GTK3
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config perl gmake
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LIBTOOL=	yes

TOOL_DEPENDS+=	p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

CONFIGURE_ARGS+=	--disable-avahi

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
