# $NetBSD: Makefile,v 1.2 2025/06/27 17:15:07 schmonz Exp $

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
CFLAGS+=		-I${BUILDLINK_PREFIX.openssl:Q}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.openssl:Q}/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG:Q}${BUILDLINK_PREFIX.openssl:Q}/lib
CFLAGS.Darwin+=		-DBIND_8_COMPAT=1
LIBS.Darwin+=		-lresolv
LIBS.SunOS+=		-lresolv

INSTALLATION_DIRS=	include lib

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
