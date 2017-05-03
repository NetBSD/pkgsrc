# $NetBSD: Makefile,v 1.59 2017/05/03 08:38:41 jperkin Exp $

DISTNAME=	thrift-${THRIFT_VERSION}
PKGNAME=	libthrift-${THRIFT_VERSION}
PKGREVISION=	39
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=thrift/${THRIFT_VERSION}/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incubator.apache.org/thrift/
COMMENT=	Cross-language data serialization library
LICENSE=	apache-2.0

# No rule to make target 'gen-cpp/Service.cpp', needed by 'Service.lo'.  Stop.
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++11
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
CXXFLAGS+=	-Wno-error=c++11-narrowing
.endif

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
