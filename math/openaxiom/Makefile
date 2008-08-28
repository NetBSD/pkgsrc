# $NetBSD: Makefile,v 1.1.1.1 2008/08/28 20:08:18 ahoka Exp $
#

DISTNAME=		open-axiom-1.2.0
PKGNAME=		${DISTNAME:S/open-/open/}
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
COMMENT=		Platform for symbolic, algebraic, and numerical computations

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gawk makeinfo
USE_LANGUAGES+=		fortran
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

BUILD_MAKE_FLAGS+=	TOOLS_PLATFORM.install=${TOOLS_PLATFORM.install:Q}

.include "options.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ./build-setup.sh

.include "../../mk/bsd.pkg.mk"
