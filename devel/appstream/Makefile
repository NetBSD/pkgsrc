# $NetBSD: Makefile,v 1.4 2023/11/08 13:18:40 wiz Exp $

DISTNAME=	appstream-0.16.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ximion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ximion/appstream/
COMMENT=	Tools and libraries to work with AppStream metadata
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		itstool pkg-config

MESON_ARGS+=	-Dsystemd=false
# for running a tool during the build
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

PKGCONFIG_OVERRIDE+=		output/meson-private/appstream.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

INSTALLATION_DIRS+=	share/examples/appstream

CONF_FILES+=	${PREFIX}/share/examples/appstream/appstream.conf ${PKG_SYSCONFDIR}/appstream.conf

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/appstream.conf ${DESTDIR}${PREFIX}/share/examples/appstream

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../textproc/libxmlb/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
