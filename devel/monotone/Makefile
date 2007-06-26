# $NetBSD: Makefile,v 1.39 2007/06/26 15:26:37 rillig Exp $
#

DISTNAME=	monotone-0.35
CATEGORIES=	devel scm
MASTER_SITES=	http://monotone.ca/downloads/0.35/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Free distributed version control system

PKGREVISION=	1

GCC_REQD+=		3.0
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST
UNLIMIT_RESOURCES+=	datasize
USE_TOOLS+=		gmake makeinfo
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	BOOST_SUFFIX=-mt

PKG_OPTIONS_VAR=	PKG_OPTIONS.monotone
PKG_SUPPORTED_OPTIONS=	inet6

CHECK_PORTABILITY_SKIP+=	debian/*

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
