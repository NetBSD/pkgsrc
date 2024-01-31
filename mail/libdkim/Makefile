# $NetBSD: Makefile,v 1.1 2024/01/31 19:19:58 schmonz Exp $

DISTNAME=		libdkim-1.0.21
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libdkim/}
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://libdkim.sourceforge.net/
COMMENT=		Portable library that signs and verifies emails
LICENSE=		apache-2.0

WRKSRC=			${WRKDIR}/${PKGBASE}
BUILD_DIRS=		src
NO_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_LIBTOOL=		yes

MAKE_ENV+=		VERSION=${PKGVERSION_NOREV:Q}
MAKE_ENV+=		LIBS=${LIBS:Q}
LIBS+=			-lssl -lcrypto
CFLAGS+=		-I${BUILDLINK_PREFIX.openssl}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.openssl}/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
CFLAGS.Darwin+=		-DBIND_8_COMPAT=1
LIBS.Darwin+=		-lresolv

INSTALLATION_DIRS=	include lib

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
