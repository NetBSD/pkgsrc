# $NetBSD: Makefile,v 1.27 2014/02/08 15:59:30 jmmv Exp $

DISTNAME=	sysbuild-2.7
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/jmmv/sysbuild/releases/download/sysbuild-2.7/

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Automates builds of NetBSD and manages source trees
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

PKG_SYSCONFSUBDIR=	sysbuild
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	SYSBUILD_CONFSUBDIR=
INSTALL_MAKE_FLAGS+=	sysbuild_confdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/sysbuild
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/default.conf

PKG_OPTIONS_VAR=	PKG_OPTIONS.sysbuild
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
PLIST_SUBST+=	TESTS=
.else
PLIST_SUBST+=	TESTS=@comment
.endif

BUILDLINK_API_DEPENDS.shtk+=	shtk>=1.3
.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
