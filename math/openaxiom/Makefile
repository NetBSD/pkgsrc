# $NetBSD: Makefile,v 1.16 2023/08/02 19:21:55 nia Exp $

DISTNAME=		open-axiom-1.4.1
PKGNAME=		${DISTNAME:S/open-/open/}
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
COMMENT=		Platform for symbolic, algebraic, and numerical computations

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo awk:run
TOOL_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

CONFIGURE_ENV=		HOST_AWK=${TOOLS_PLATFORM.awk:Q}
BUILD_MAKE_FLAGS+=	TOOLS_PLATFORM.install=${TOOLS_PLATFORM.install:Q}

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

# XXX: these files are not PIE
CHECK_PIE_SKIP+=	lib/open-axiom/*/${PKGVERSION_NOREV}/bin/AXIOMsys
CHECK_PIE_SKIP+=	lib/open-axiom/*/${PKGVERSION_NOREV}/bin/bootsys

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
