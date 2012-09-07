# $NetBSD: Makefile,v 1.10 2012/09/07 19:16:22 adam Exp $
#

DISTNAME=	dconf-0.12.1
PKGNAME=	dconf-editor-0.12.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/0.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/dconf
COMMENT=	Backend for gsettings
LICENSE=	gnu-lgpl-v2.1

DISTINFO_FILE=	${.CURDIR}/../../devel/dconf/distinfo
PATCHDIR=	${.CURDIR}/../../devel/dconf/patches

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-editor
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

BUILD_DIRS=	editor
INSTALL_DIRS=	editor

SUBST_CLASSES+=	prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	editor/dconf-model.vala
SUBST_VARS.prefix=	PREFIX

# SUBST doesn't touch - force rebuild
pre-build:
	${RM} ${WRKSRC}/editor/dconf-model.c

.include "../../devel/glib2/schemas.mk"
BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala016/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
