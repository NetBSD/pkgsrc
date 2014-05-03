# $NetBSD: Makefile,v 1.21 2014/05/03 13:14:37 alnsn Exp $
#

DISTNAME=	kyua-cli-0.8
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://kyua.googlecode.com/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://code.google.com/p/kyua/
COMMENT=	Kyua (automated testing framework) - Command line interface
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes
USE_LANGUAGES=		c++
USE_TOOLS=		pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.kyua-cli
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

CONFIGURE_ARGS+=	KYUA_CONFSUBDIR=
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-doxygen

PKG_SYSCONFSUBDIR=	kyua

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-atf
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS=@comment
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/tests
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
	    ${DESTDIR}${PREFIX}/tests/Kyuafile

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/kyua-testers/buildlink3.mk"
.include "../../devel/lutok/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
