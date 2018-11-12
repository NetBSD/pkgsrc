# $NetBSD: Makefile,v 1.72 2018/11/12 03:52:44 ryoon Exp $

DISTNAME=	monsoon-0.20
PKGREVISION=	65
CATEGORIES=	net
MASTER_SITES=	http://www.monsoon-project.org/jaws/data/files/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.monsoon-project.org/
COMMENT=	Open source GTK+ bittorrent client

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake gtar intltool perl pkg-config msgfmt
EXTRACT_USING=	gtar

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure Monsoon/Makefile.in
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../lang/mono/buildlink3.mk"
.include "../../net/mono-nat/buildlink3.mk"
.include "../../net/monotorrent/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
