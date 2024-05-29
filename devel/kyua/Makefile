# $NetBSD: Makefile,v 1.30 2024/05/29 16:32:12 adam Exp $

DISTNAME=	kyua-0.13
PKGREVISION=	18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/kyua/releases/download/${DISTNAME}/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/jmmv/kyua/
COMMENT=	Testing framework for infrastructure software
LICENSE=	modified-bsd

CONFLICTS=	kyua-atf-compat-[0-9]* kyua-cli-[0-9]* kyua-testers-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.kyua
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

CONFIGURE_ARGS+=	KYUA_CONFSUBDIR=
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-doxygen

PKG_SYSCONFSUBDIR=	kyua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-atf
PLIST_SUBST+=		TESTS=

post-install: post-install-tests
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS="@comment "
.endif
PRINT_PLIST_AWK+=	{ sub("^tests/", "$${TESTS}tests/"); }

.PHONY: post-install-tests
post-install-tests:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/tests
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
	    ${DESTDIR}${PREFIX}/tests/Kyuafile

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/lutok/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
