# $NetBSD: Makefile,v 1.1.1.1 2003/12/29 00:49:48 xtraeme Exp $
#

DISTNAME=	gnome-system-monitor-2.4.0
PKGNAME=	${DISTNAME:S/gnome/gnome2/}
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-system-monitor/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 system monitor program

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBS+=			-lutil
GCONF2_SCHEMAS+=	gnome-system-monitor.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgtop2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libwnck/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/startup-notification/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
