# $NetBSD: Makefile,v 1.15 2012/03/09 14:31:07 fhajny Exp $

DISTNAME=	thrift-${THRIFT_VERSION}
PKGNAME=	libthrift-${THRIFT_VERSION}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=thrift/${THRIFT_VERSION}/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://incubator.apache.org/thrift/
COMMENT=	Cross-language data serialization library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/thrift-${THRIFT_VERSION}
THRIFT_VERSION=	0.7.0

pre-build:
	${CHMOD} 0755 ${WRKSRC}/lib/erl/rebar

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
