# $NetBSD: Makefile,v 1.12 2017/11/01 06:44:49 maya Exp $

DISTNAME=	cmake-fedora-2.6.0-modules-only
PKGNAME=	${DISTNAME:S/-modules-only//}
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

.include "../../devel/cmake/Makefile.version"
PLIST_SUBST+=	CMAKE_API=${CMAKE_API}

INSTALLATION_DIRS+=	share/cmake-${CMAKE_API}/Modules

do-install:
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' Modules ${DESTDIR}${PREFIX}/share/cmake-${CMAKE_API}

.include "../../mk/bsd.pkg.mk"
