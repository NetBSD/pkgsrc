# $NetBSD: Makefile,v 1.39 2018/08/22 09:46:06 wiz Exp $

DISTNAME=	remmina-0.9.3
PKGREVISION=	34
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=remmina/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://remmina.sourceforge.net/
COMMENT=	Remmina is a remote desktop client based on GTK+

DEPENDS+=	rdesktop>=1.6.0:../../net/rdesktop

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_TOOLS+=	intltool perl pkg-config gmake msgfmt

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvncserver=		libvncserver>=0.9.1
.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.libgcrypt=		libgcrypt>=1.4.4
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libssh=		libssh>=0.54
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk" # ???
.include "../../x11/vte/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
