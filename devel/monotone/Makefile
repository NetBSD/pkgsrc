# $NetBSD: Makefile,v 1.89 2014/05/03 13:14:37 alnsn Exp $
#

DISTNAME=	monotone-1.0
PKGREVISION=	17
CATEGORIES=	devel scm
MASTER_SITES=	http://monotone.ca/downloads/1.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Free distributed version control system

LUA_VERSIONS_ACCEPTED=	51

GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
INFO_FILES=		yes
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # OR newer
TEST_TARGET=		check
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake makeinfo pax perl:run pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-system-pcre

INSTALL_MAKE_FLAGS+=	bashcompdir=${PREFIX:Q}/share/examples/monotone

PKG_OPTIONS_VAR=	PKG_OPTIONS.monotone
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

CHECK_INTERPRETER_SKIP+=	share/monotone/contrib/*
CHECK_PORTABILITY_SKIP+=	debian/*

REPLACE_PERL=			extra/bin/mtn-cleanup
REPLACE_SH=			mtnopt
# The following are optional scripts for hooks.  We do not replace their
# interpreter because we want to avoid a dependency on them.  (Ideally they
# should be in separate packages with appropriate dependencies.)
CHECK_INTERPRETER_SKIP=	share/monotone/scripts/monotone-ciabot.py
CHECK_INTERPRETER_SKIP+=	share/monotone/scripts/monotone-mail-notify

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

INSTALLATION_DIRS+=	share/monotone

BUILDLINK_API_DEPENDS.pcre+=	pcre>=7.6

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
