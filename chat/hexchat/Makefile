# $NetBSD: Makefile,v 1.46 2020/06/02 08:23:17 adam Exp $

DISTNAME=	hexchat-2.14.3
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	https://dl.hexchat.net/hexchat/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hexchat.github.io/
COMMENT=	IRC client based on XChat
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit

USE_TOOLS+=	pkg-config msgfmt xgettext
USE_LANGUAGES=	c c++

# XXX fails without GNU msgfmt
_TOOLS_USE_PKGSRC.msgfmt=	yes

MESON_ARGS+=		-Dwith-text=true
MESON_ARGS+=		-Dwith-appdata=false

REPLACE_PYTHON+=	plugins/perl/generate_header.py
REPLACE_PYTHON+=	src/common/make-te.py

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}

LDFLAGS.SunOS+=		-lsocket -lnsl

PKGCONFIG_OVERRIDE+=	data/pkgconfig/hexchat-plugin.pc.in

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
