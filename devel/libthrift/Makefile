# $NetBSD: Makefile,v 1.69 2018/08/22 09:43:33 wiz Exp $

DISTNAME=	thrift-0.11.0
PKGNAME=	lib${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=thrift/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incubator.apache.org/thrift/
COMMENT=	Cross-language data serialization library
LICENSE=	apache-2.0

# No rule to make target 'gen-cpp/Service.cpp', needed by 'Service.lo'.  Stop.
#MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config yacc
GNU_CONFIGURE=		yes

TEST_TARGET=	check

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
