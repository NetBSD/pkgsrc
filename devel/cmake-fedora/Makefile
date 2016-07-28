# $NetBSD: Makefile,v 1.11 2016/07/28 17:52:08 prlw1 Exp $

DISTNAME=	cmake-fedora-2.6.0-modules-only
PKGNAME=	${DISTNAME:S/-modules-only//}
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/c/m/cmake-fedora/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/cmake-fedora/
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
