# $NetBSD: Makefile,v 1.13 2020/07/31 09:21:23 wiz Exp $

DISTNAME=	cmake-fedora-2.6.0-modules-only
PKGNAME=	${DISTNAME:S/-modules-only//}
PKGREVISION=	1
CATEGORIES=	devel
# Doesn't host our old version, fedorahosted retired.
#MASTER_SITES=	https://releases.pagure.org/cmake-fedora/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pagure.io/cmake-fedora
COMMENT=	Set of cmake modules for fedora developers
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Modules
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

NO_BUILD=	yes

WRKSRC=		${WRKDIR}

.include "../../devel/cmake/version.mk"

PLIST_SUBST+=	CMAKE_API=${CMAKE_API}

INSTALLATION_DIRS+=	share/cmake-${CMAKE_API}/Modules

do-install:
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' Modules ${DESTDIR}${PREFIX}/share/cmake-${CMAKE_API}

.include "../../mk/bsd.pkg.mk"
