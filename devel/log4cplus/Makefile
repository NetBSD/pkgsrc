# $NetBSD: Makefile,v 1.6 2013/09/23 13:55:50 obache Exp $
#

DISTNAME=	log4cplus-1.1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=log4cplus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://log4cplus.sourceforge.net/
COMMENT=	Logging API for C++
LICENSE=	apache-2.0 AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++	# C for configure

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS+=	-Werror=ignored-attributes
.endif

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

# TLS is not supported by NetBSD<6
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-*)
CONFIGURE_ENV+=	ac_cv_thread_local=no
CONFIGURE_ENV+=	ac_cv__thread_keyword=no
.endif

.include "../../mk/bsd.pkg.mk"
