# $NetBSD: Makefile,v 1.12 2022/08/09 12:08:27 jperkin Exp $
#

DISTNAME=	log4cplus-2.0.3
CATEGORIES=	devel
GITHUB_RELEASE=	REL_2_0_3
MASTER_SITES=	${MASTER_SITE_GITHUB:=log4cplus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://log4cplus.sourceforge.io/
COMMENT=	Logging API for C++
LICENSE=	apache-2.0 AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf gmake
USE_LANGUAGES=	c99 c++11	# C for configure

CONFIGURE_ARGS+=	--with-iconv
CONFIGURE_ARGS+=	--without-wchar_t-support
CONFIGURE_ARGS+=	--without-qt
CONFIGURE_ARGS+=	--without-qt5
CONFIGURE_ARGS+=	--without-python

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS+=	-Werror=ignored-attributes
.endif

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no
CONFIGURE_ARGS+=	--enable-threads

# TLS is not supported by NetBSD<6
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-*)
CONFIGURE_ENV+=	ac_cv_thread_local=no
CONFIGURE_ENV+=	ac_cv__thread_keyword=no
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
