# $NetBSD: Makefile,v 1.14 2024/05/29 16:32:13 adam Exp $

DISTNAME=	libgnt-2.14.0
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/pidgin/libgnt
COMMENT=	GLib Ncurses Toolkit
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		nc
SUBST_STAGE.nc=		pre-configure
SUBST_MESSAGE.nc=	Correcting the path to ncurses.
SUBST_FILES.nc+=	meson.build
SUBST_SED.nc+=		-e "s,ncurses_sys_prefix = '/usr',ncurses_sys_prefix = '${PREFIX}',g"

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/gnt.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
