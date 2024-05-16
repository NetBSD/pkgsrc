# $NetBSD: Makefile,v 1.31 2024/05/16 06:14:37 wiz Exp $

DISTNAME=	profanity-0.14.0
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=profanity-im/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://profanity-im.github.io/
COMMENT=	Console based XMPP client inspired by irssi
LICENSE=	gnu-gpl-v3

FAKE_NCURSES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

USE_CURSES=	wide

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	configure
SUBST_SED.python=	-e 's,"python",\"python-${PYVERSSUFFIX}\",g'
SUBST_SED.python+=	-e 's,"python-embed",\"python-${PYVERSSUFFIX}-embed\",g'
SUBST_SED.python+=	-e 's,\"python\",\"python-${PYVERSSUFFIX}\",g'
SUBST_SED.python+=	-e 's,\"python-embed\",\"python-${PYVERSSUFFIX}-embed\",g'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Setting path to OpenSSL certificates.
SUBST_FILES.paths=	src/config/preferences.c
SUBST_VARS.paths=	SSLCERTS

CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-c-plugins
CONFIGURE_ARGS+=	--enable-python-plugins
CONFIGURE_ARGS+=	--enable-omemo

.include "options.mk"
.include "../../chat/libstrophe/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../chat/libsignal-protocol-c/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=		sqlite3>=3.22.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
