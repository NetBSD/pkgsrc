# $NetBSD: Makefile,v 1.15 2025/10/19 13:43:08 adam Exp $

DISTNAME=	log4cplus-2.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=log4cplus/}
GITHUB_RELEASE=	REL_${PKGVERSION_NOREV:S/./_/g}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://log4cplus.sourceforge.io/
COMMENT=	Logging API for C++
LICENSE=	apache-2.0 AND 2-clause-bsd

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv
CONFIGURE_ARGS+=	--without-wchar_t-support
CONFIGURE_ARGS+=	--without-qt
CONFIGURE_ARGS+=	--without-qt5
CONFIGURE_ARGS+=	--without-python
TEST_TARGET=		check

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS+=	-Werror=ignored-attributes
.endif

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no
CONFIGURE_ARGS+=	--enable-threads

# TLS is not supported by NetBSD<6
.if ${MACHINE_PLATFORM:MNetBSD-[0-5].*-*}
CONFIGURE_ENV+=	ac_cv_thread_local=no
CONFIGURE_ENV+=	ac_cv__thread_keyword=no
.endif

LIBS+=		${BUILDLINK_LDADD.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
