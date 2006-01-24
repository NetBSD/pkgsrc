# $NetBSD: Makefile,v 1.30 2006/01/24 07:32:34 wiz Exp $
#

DISTNAME=	gnome-system-monitor-2.12.1
PKGNAME=	${DISTNAME:S/gnome/gnome2/}
PKGREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-system-monitor/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 system monitor program

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake pkg-config

LIBS+=			-lutil
GCONF2_SCHEMAS+=	gnome-system-monitor.schemas

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize
	cd ${WRKSRC} && autoconf

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
