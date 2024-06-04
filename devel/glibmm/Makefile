# $NetBSD: Makefile,v 1.99 2024/06/04 07:45:51 adam Exp $

DISTNAME=	glibmm-2.66.7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for glib (2.4 API)
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11 regex
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 perl:run pkg-config
PKGCONFIG_OVERRIDE+=	gio/giomm.pc.in
PKGCONFIG_OVERRIDE+=	glib/glibmm.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

REPLACE_PERL+=	tools/generate_wrap_init.pl.in
REPLACE_PERL+=	tools/gmmproc.in

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	tools/generate_wrap_init.pl.in
SUBST_FILES.path+=	tools/gmmproc.in
SUBST_SED.path=		-e 's,@PERL@,${PERL5},'
SUBST_VARS.path=	M4

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notmac

.if ${OPSYS} != "Darwin"
PLIST.notmac=	yes
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.66.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/mm-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
