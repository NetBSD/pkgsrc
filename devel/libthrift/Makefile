# $NetBSD: Makefile,v 1.2 2010/05/15 07:17:16 adam Exp $

DISTNAME=	thrift-${THRIFT_VERSION}-incubating
PKGNAME=	libthrift-${THRIFT_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=incubator/thrift/${THRIFT_VERSION}-incubating/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://incubator.apache.org/thrift/
COMMENT=	Cross-language data serialization library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/thrift-${THRIFT_VERSION}
THRIFT_VERSION=	0.2.0

# FIXME: These should be options
CONFIGURE_ARGS+=	--without-csharp
CONFIGURE_ARGS+=	--without-erlang
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--without-py
CONFIGURE_ARGS+=	--without-ruby

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
