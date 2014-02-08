# $NetBSD: Makefile,v 1.3 2014/02/08 15:59:30 jmmv Exp $
#

DISTNAME=	kyua-testers-0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://kyua.googlecode.com/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://code.google.com/p/kyua/
COMMENT=	Kyua (automated testing framework) - Testers
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes
USE_LANGUAGES=		c

PKG_OPTIONS_VAR=	PKG_OPTIONS.kyua-testers
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

CONFIGURE_ARGS+=	--without-doxygen

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
.  include "../../devel/atf/buildlink3.mk"
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-atf
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS=@comment
.endif

.include "../../mk/bsd.pkg.mk"
