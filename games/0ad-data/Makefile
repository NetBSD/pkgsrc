# $NetBSD: Makefile,v 1.3 2023/05/04 17:30:07 nikita Exp $

.include "../../games/0ad/Makefile.common"

DISTNAME=	${DISTVERSION}-data
PKGNAME=	${DISTNAME:S/-unix-data//:S/0ad-/0ad-data-/:S/-alpha/.alpha/}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datafiles for the 0ad game
LICENSE=	public-domain AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix-data//}
USE_LANGUAGES=	# none

USE_TOOLS+=	pax tar

DATADIR_0AD=	${PREFIX}/share/0ad

INSTALLATION_DIRS+=	${DATADIR_0AD}

NO_BUILD=	yes

pre-install:
	# We can't use INSTALLATION_DIRS for tar command.
	${MKDIR} ${DESTDIR}${DATADIR_0AD}/mods/public
	${MKDIR} ${DESTDIR}${DATADIR_0AD}/mods/mod
	${TAR} xf ${WRKSRC}/binaries/data/mods/public/public.zip \
		-C ${DESTDIR}${DATADIR_0AD}/mods/public --no-same-permissions
	${TAR} xf ${WRKSRC}/binaries/data/mods/mod/mod.zip \
		-C ${DESTDIR}${DATADIR_0AD}/mods/mod --no-same-permissions
	${RM} ${WRKSRC}/binaries/data/mods/public/public.zip
	${RM} ${WRKSRC}/binaries/data/mods/mod/mod.zip

do-install:
	${RUN} cd ${WRKSRC}/binaries/data && ${PAX} -rw . ${DESTDIR}${DATADIR_0AD}

.include "../../mk/bsd.pkg.mk"
