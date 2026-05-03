# $NetBSD: Makefile,v 1.1 2026/05/03 09:51:11 vins Exp $

DISTNAME=	gcr-4.4.0.1
PKGNAME=	${DISTNAME:S/gcr/gcr4/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gcr/4.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Library for crypto UI and related tasks
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2

USE_TOOLS+=	bash:test gdbus-codegen intltool msgfmt pkg-config

USE_PKGLOCALEDIR=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=		-lsocket

REPLACE_BASH=		gcr/fixtures/gnupg-mock/mock-status-and-attribute

TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/output/gck
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/output/gc

MESON_ARGS+=		--localedir=${PKGLOCALEDIR}/locale \
			-Dgpg_path=${PREFIX}/bin/gpg2 \
			-Dssh_agent=true \
			-Dsystemd=disabled

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/gck-2.pc \
				output/meson-private/gcr-base-4.pc \
				output/meson-private/gcr-ui-4.pc \
				output/meson-private/gcr-4.pc

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
