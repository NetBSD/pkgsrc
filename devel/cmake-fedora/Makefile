# $NetBSD: Makefile,v 1.9 2015/07/31 13:01:43 ryoon Exp $
#

DISTNAME=	cmake-fedora-2.1.3-modules-only
PKGNAME=	${DISTNAME:S/-modules-only//}
PKGREVISION=	1
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

INSTALLATION_DIRS+=	share/cmake-3.3/Modules

do-install:
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' Modules ${DESTDIR}${PREFIX}/share/cmake-3.3

.include "../../mk/bsd.pkg.mk"
