# $NetBSD: Makefile,v 1.3 2009/04/18 11:17:33 asau Exp $
#

DISTNAME=		open-axiom-1.2.1
PKGNAME=		${DISTNAME:S/open-/open/}
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
COMMENT=		Platform for symbolic, algebraic, and numerical computations

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo awk:run
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

CONFIGURE_ENV=		HOST_AWK=${TOOLS_PLATFORM.awk:Q}
BUILD_MAKE_FLAGS+=	TOOLS_PLATFORM.install=${TOOLS_PLATFORM.install:Q}

.include "options.mk"

SUBST_CLASSES+=			dragonfly
SUBST_STAGE.dragonfly=		post-patch
SUBST_MESSAGE.dragonfly=	Fixing BSD Family pattern
SUBST_FILES.dragonfly+=		configure
SUBST_SED.dragonfly=		-e 's/\*bsd\*)/*bsd*|*dragonfly*)/'

.include "../../mk/bsd.pkg.mk"
