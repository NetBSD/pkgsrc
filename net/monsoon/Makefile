# $NetBSD: Makefile,v 1.4 2009/06/22 02:02:46 ahoka Exp $

DISTNAME=	monsoon-0.15
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.monsoon-project.org/jaws/data/files/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.monsoon-project.org/
COMMENT=	Open source GTK+ bittorrent client

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake gtar perl pkg-config msgfmt
EXTRACT_USING=	gtar

DEPENDS+=	intltool>0.40.0:../../textproc/intltool

.include "../../lang/mono/buildlink3.mk"
.include "../../net/monotorrent/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
