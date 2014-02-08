# $NetBSD: Makefile,v 1.4 2014/02/08 15:59:30 jmmv Exp $
#

DISTNAME=	kyua-atf-compat-0.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://kyua.googlecode.com/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://code.google.com/p/kyua/
COMMENT=	Kyua (automated testing framework) - ATF compatibility tools
LICENSE=	modified-bsd

DEPENDS=	kyua-cli>=0.5:../../devel/kyua-cli

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes
USE_TOOLS=		pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.kyua-atf-compat
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

CONFIGURE_ARGS+=	ATF_CONFSUBDIR=
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	atf

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-atf
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS=@comment
.endif

.include "../../mk/bsd.pkg.mk"
