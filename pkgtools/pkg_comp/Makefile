# $NetBSD: Makefile,v 1.60 2017/09/02 16:18:56 jlam Exp $

DISTNAME=	pkg_comp-2.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/}pkg_comp/releases/download/pkg_comp-2.0/

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Automates builds of packages and manages pkgsrc trees
LICENSE=	modified-bsd

DEPENDS=	sandboxctl>=1.0:../../sysutils/sandboxctl

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

PKG_SYSCONFSUBDIR=	pkg_comp
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	PKG_COMP_CONFSUBDIR=
CONFIGURE_ARGS+=	SANDBOXCTL=${PREFIX}/sbin/sandboxctl
INSTALL_MAKE_FLAGS+=	pkg_comp_confdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/pkg_comp
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/default.conf
CONF_FILES+=		${EGDIR}/extra.mk.conf ${PKG_SYSCONFDIR}/extra.mk.conf
CONF_FILES+=		${EGDIR}/sandbox.conf ${PKG_SYSCONFDIR}/sandbox.conf

# Substitute for the correct location of the configuration files
# for sandboxctl.
SUBST_CLASSES+=		sandboxctl
SUBST_STAGE.sandboxctl=	pre-configure
SUBST_FILES.sandboxctl=	sandbox.conf.in
SUBST_SED.sandboxctl=	-e 's,__PKG_COMP_BASESYSCONFDIR__/sandboxctl/,${SANDBOXCTL_SYSCONFDIR}/,g'
SANDBOXCTL_SYSCONFDIR=	${PKG_SYSCONFDIR.sandboxctl:U${PKG_SYSCONFBASE}/sandboxctl}

PKG_OPTIONS_VAR=	PKG_OPTIONS.pkg_comp
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--with-atf=no
PLIST_SUBST+=		TESTS=@comment

post-install:
	rm -rf "${PREFIX}/share/tests/pkg_comp"
.endif

BUILDLINK_API_DEPENDS.shtk+=	shtk>=1.7
.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
