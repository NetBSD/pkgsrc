# $NetBSD: Makefile,v 1.15 2005/09/30 13:18:24 jmmv Exp $
#

DISTNAME=	monotone-0.23
CATEGORIES=	devel
MASTER_SITES=	http://www.venge.net/monotone/downloads/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.venge.net/monotone/
COMMENT=	Free distributed version control system

GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
INFO_FILES=		monotone.info
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_MAKEINFO=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	BOOST_SUFFIX=-mt

PKG_OPTIONS_VAR=	PKG_OPTIONS.monotone
PKG_SUPPORTED_OPTIONS=	inet6
PKG_OPTIONS_LEGACY_OPTS+=	ipv6:inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
