# $NetBSD: Makefile,v 1.1 2017/02/17 21:23:42 jmmv Exp $

DISTNAME=	sandboxctl-1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/}sandboxctl/releases/download/sandboxctl-1.0/

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Manages chroot-based sandboxes
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

PKG_SYSCONFSUBDIR=	sandboxctl
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	SANDBOXCTL_CONFSUBDIR=
INSTALL_MAKE_FLAGS+=	sandboxctl_confdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/sandboxctl
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/default.conf

PKG_OPTIONS_VAR=	PKG_OPTIONS.sandboxctl
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
	rm -rf "${PREFIX}/share/tests/sandboxctl"
.endif

BUILDLINK_API_DEPENDS.shtk+=	shtk>=1.7
.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
