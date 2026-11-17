# $NetBSD: Makefile,v 1.55 2026/11/17 21:42:57 ktnb Exp $

DISTNAME=	profanity-0.19.0
CATEGORIES=	chat
MASTER_SITES=	https://profanity-im.github.io/tarballs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://profanity-im.github.io/
COMMENT=	Console based XMPP client inspired by irssi
LICENSE=	gnu-gpl-v3

FAKE_NCURSES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config cmake
USE_CURSES=	wide

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	meson.build
SUBST_SED.python+=	-e 's,'python-embed','python-${PYVERSSUFFIX}-embed',g'
SUBST_SED.python+=	-e 's,'python3-embed','python-${PYVERSSUFFIX}-embed',g'

MESON_ARGS+=		-Dpython-plugins=enabled
MESON_ARGS+=		-Dc-plugins=enabled
MESON_ARGS+=		-Domemo=enabled

.include "options.mk"
.include "../../chat/libstrophe/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../chat/libsignal-protocol-c/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=		sqlite3>=3.22.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
