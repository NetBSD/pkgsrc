# $NetBSD: Makefile,v 1.34 2017/05/29 12:20:23 wiz Exp $

DISTNAME=	dconf-0.26.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/dconf
COMMENT=	Backend for gsettings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

SUBST_CLASSES+=		sysdir
SUBST_MESSAGE.sysdir=	Fixes hard-coded dconf database directory name
SUBST_STAGE.sysdir=	post-configure
SUBST_FILES.sysdir+=	engine/dconf-engine-source-system.c
SUBST_FILES.sysdir+=	engine/dconf-engine-profile.c
SUBST_FILES.sysdir+=	tests/engine.c
SUBST_FILES.sysdir+=	bin/dconf-update.c
SUBST_FILES.sysdir+=	bin/dconf-update.vala
SUBST_SED.sysdir=	-e s,/etc,${PKG_SYSCONFDIR},g

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES.Darwin+=	libname
SUBST_STAGE.libname=	pre-configure
SUBST_FILES.libname=	client/Makefile.in
SUBST_FILES.libname+=	gsettings/Makefile.in
SUBST_SED.libname=	-e "s|-Wl,-soname=|-install_name ${PREFIX}/lib/|g"
SUBST_SED.libname+=	-e "/^libdconfsettings_so_LDFLAGS/s,$$, -install_name ${PREFIX}/lib/gio/modules/libdconfsettings.so,g"

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_DEPMETHOD.vala=	build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.18.0
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
.include "../../devel/glib2/modules.mk"
.include "../../mk/bsd.pkg.mk"
