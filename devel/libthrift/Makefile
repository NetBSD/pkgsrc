# $NetBSD: Makefile,v 1.37 2014/02/12 23:17:48 tron Exp $

DISTNAME=	thrift-${THRIFT_VERSION}
PKGNAME=	libthrift-${THRIFT_VERSION}
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=thrift/${THRIFT_VERSION}/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://incubator.apache.org/thrift/
COMMENT=	Cross-language data serialization library
LICENSE=	apache-2.0

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config yacc
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LEXLIB=""

WRKSRC=		${WRKDIR}/thrift-${THRIFT_VERSION}
THRIFT_VERSION=	0.7.0
TEST_TARGET=	check

pre-build:
	${CHMOD} 0755 ${WRKSRC}/lib/erl/rebar

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11 -Wno-error=c++11-narrowing
.endif

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
