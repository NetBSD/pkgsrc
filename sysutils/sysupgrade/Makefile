# $NetBSD: Makefile,v 1.14 2019/06/03 20:35:55 triaxx Exp $

DISTNAME=	sysupgrade-1.5
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/}
MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Automate upgrades of NetBSD
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

BUILD_DEFS+=		VARBASE
SYSUPGRADE_CACHEDIR=	${VARBASE}/cache/sysupgrade
OWN_DIRS_PERMS=		${SYSUPGRADE_CACHEDIR} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
CONFIGURE_ARGS+=	SYSUPGRADE_CACHEDIR=${SYSUPGRADE_CACHEDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/sysupgrade
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/sysupgrade.conf

PKG_OPTIONS_VAR=	PKG_OPTIONS.sysupgrade
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
PLIST_SUBST+=	TESTS=
.else
PLIST_SUBST+=	TESTS=@comment
.endif

BUILDLINK_API_DEPENDS.shtk+=	shtk>=1.3
.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
