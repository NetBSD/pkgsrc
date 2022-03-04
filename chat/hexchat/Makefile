# $NetBSD: Makefile,v 1.56 2022/03/04 07:48:16 nia Exp $

DISTNAME=	hexchat-2.16.1
CATEGORIES=	chat
MASTER_SITES=	https://dl.hexchat.net/hexchat/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hexchat.github.io/
COMMENT=	IRC client based on XChat
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit

USE_TOOLS+=	pkg-config msgfmt xgettext

USE_LANGUAGES=	c c++

MESON_ARGS+=		-Dtext-frontend=true
MESON_ARGS+=		-Dinstall-appdata=false

REPLACE_PYTHON+=	plugins/perl/generate_header.py
REPLACE_PYTHON+=	src/common/make-te.py

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# msgfmt: unknown option -- xml
TOOLS_PLATFORM.msgfmt=
.endif

PKGCONFIG_OVERRIDE+=	data/pkgconfig/hexchat-plugin.pc.in

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
# Whether Python is required strictly as a build tool or also at runtime is
# determined in options.mk, and PYTHON_FOR_BUILD_ONLY is set there, if needed.
.include "../../lang/python/tool.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
