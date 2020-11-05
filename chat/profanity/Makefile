# $NetBSD: Makefile,v 1.4 2020/11/05 09:07:36 ryoon Exp $

DISTNAME=	profanity-0.9.5
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://profanity-im.github.io/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://profanity-im.github.io/
COMMENT=	Console based XMPP client inspired by irssi
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf pkg-config

AUTOCONF_REQD=	2.69

FAKE_NCURSES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

USE_CURSES=	wide

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	configure.ac
SUBST_SED.python=	-e 's,python-config,python${PYVERSSUFFIX}-config,g'

CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-c-plugins
CONFIGURE_ARGS+=	--enable-python-plugins
CONFIGURE_ARGS+=	--enable-omemo

pre-configure:
	cd ${WRKSRC} && autoconf

BUILDLINK_API_DEPENDS.libmesode+=	libmesode>=0.9.1
.include "../../chat/libmesode/buildlink3.mk"
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
