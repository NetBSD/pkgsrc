# $NetBSD: Makefile,v 1.6 2014/03/01 09:41:12 obache Exp $
#

DISTNAME=	cmake-fedora-1.2.7-modules-only
PKGNAME=	${DISTNAME:S/-modules-only//}
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/c/m/cmake-fedora/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/cmake-fedora/
COMMENT=	Set of cmake modules for fedora developers
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Modules
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

NO_BUILD=	yes

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	share/cmake-2.8/Modules

do-install:
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' Modules ${DESTDIR}${PREFIX}/share/cmake-2.8

.include "../../mk/bsd.pkg.mk"
