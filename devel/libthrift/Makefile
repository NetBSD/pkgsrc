# $NetBSD: Makefile,v 1.6 2011/05/20 01:07:12 tonnerre Exp $

DISTNAME=	thrift-${THRIFT_VERSION}
PKGNAME=	libthrift-${THRIFT_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=incubator/thrift/${THRIFT_VERSION}/}

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
THRIFT_VERSION=	0.6.0

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
