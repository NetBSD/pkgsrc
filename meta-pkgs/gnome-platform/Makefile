# $NetBSD: Makefile,v 1.1.1.1 2008/01/09 18:47:36 drochner Exp $

DISTNAME=	gnome-platform-2.20.3
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for basic components of the GNOME desktop

DEPENDS+=	GConf>=2.20.1:../../devel/GConf
DEPENDS+=	ORBit2>=2.14.10:../../net/ORBit2
DEPENDS+=	at-spi>=1.20.1:../../devel/at-spi
DEPENDS+=	atk>=1.20.0:../../devel/atk
DEPENDS+=	libaudiofile>=0.2.6:../../audio/libaudiofile
DEPENDS+=	esound>=0.2.38:../../audio/esound
DEPENDS+=	gail>=1.20.2:../../devel/gail
DEPENDS+=	glib2>=2.14.4:../../devel/glib2
DEPENDS+=	gnome-mime-data>=2.18.0:../../databases/gnome-mime-data
DEPENDS+=	gnome-vfs>=2.20.1:../../sysutils/gnome-vfs
DEPENDS+=	gnome-vfs-monikers>=2.15.3:../../sysutils/gnome-vfs-monikers
DEPENDS+=	gtk2+>=2.12.4:../../x11/gtk2
DEPENDS+=	gtk-doc>=1.9:../../textproc/gtk-doc
DEPENDS+=	intltool>=0.36.3:../../textproc/intltool
DEPENDS+=	libIDL>=0.8.9:../../net/libIDL
DEPENDS+=	libart>=2.3.19:../../graphics/libart
DEPENDS+=	libbonobo>=2.20.3:../../devel/libbonobo
DEPENDS+=	libbonoboui>=2.20.0:../../devel/libbonoboui
DEPENDS+=	libglade>=2.6.2:../../devel/libglade
DEPENDS+=	libgnome>=2.20.1.1:../../devel/libgnome
DEPENDS+=	libgnomecanvas>=2.20.1.1:../../graphics/libgnomecanvas
DEPENDS+=	libgnomeui>=2.20.1.1:../../devel/libgnomeui
DEPENDS+=	libxml2>=2.6.30:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.22:../../textproc/libxslt
DEPENDS+=	pango>=1.18.4:../../devel/pango

# XXX gnome-keyring is distributed with the "desktop" set, but is required
# by libgnomeui. List it here to avoid circular dependency.
DEPENDS+=	gnome-keyring>=2.20.3:../../security/gnome-keyring

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
