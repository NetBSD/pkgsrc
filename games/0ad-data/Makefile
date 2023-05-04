# $NetBSD: Makefile,v 1.2 2023/05/04 15:26:02 nikita Exp $

.include "../../games/0ad/Makefile.common"

DISTNAME=	${DISTVERSION}-data
PKGNAME=	${DISTNAME:S/-unix-data//:S/0ad-/0ad-data-/:S/-alpha/.alpha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datafiles for the 0ad game
LICENSE=	public-domain AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix-data//}
USE_LANGUAGES=	# none

USE_TOOLS+=	pax

DATADIR_0AD=	${PREFIX}/share/0ad

INSTALLATION_DIRS+=	${DATADIR_0AD}

NO_BUILD=	yes

do-install:
	${RUN} cd ${WRKSRC}/binaries/data && ${PAX} -rw . ${DESTDIR}${DATADIR_0AD}

.include "../../mk/bsd.pkg.mk"
