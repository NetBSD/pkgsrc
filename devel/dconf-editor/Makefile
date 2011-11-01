# $NetBSD: Makefile,v 1.3 2011/11/01 06:00:54 sbd Exp $
#

DISTNAME=	dconf-0.5.1
PKGNAME=	dconf-editor-0.5.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/dconf
COMMENT=	Backend for gsettings
#LICENSE=	# TODO: (see mk/license.mk)

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
BUILD_DEPENDS+=	vala-[0-9]*:../../lang/vala

# SUBST doesn't touch - force rebuild
pre-build:
	${RM} ${WRKSRC}/editor/dconf-model.c

.include "../../devel/dconf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
