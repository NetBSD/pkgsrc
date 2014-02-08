# $NetBSD: Makefile,v 1.6 2014/02/08 15:59:30 jmmv Exp $

DISTNAME=	shtk-1.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/shtk/releases/download/shtk-1.3/

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

CONFIGURE_ARGS+=	SHTK_SHELL="${SH}"

PKG_OPTIONS_VAR=	PKG_OPTIONS.shtk
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-atf=yes
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--with-atf=no
PLIST_SUBST+=		TESTS=@comment
.endif

.include "../../mk/bsd.pkg.mk"
