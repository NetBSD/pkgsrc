# $NetBSD: Makefile,v 1.26 2023/10/29 17:56:02 wiz Exp $

DISTNAME=	stegavorto-src-2011.05.26
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hamsterrepublic.com/games/stegavorto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://james.hamsterrepublic.com/?p=130
COMMENT=	Discover secret messages embedded in the works of great authors
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py27-game

WRKSRC=		${WRKDIR}/stegavorto-src
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS=	bin share/stegavorto/data

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/stegavorto
	${ECHO} "cd ${PREFIX}/share/stegavorto && ${PYTHONBIN} stegavorto.py" >> ${WRKSRC}/stegavorto

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/stegavorto ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/stegavorto.py \
		${DESTDIR}${PREFIX}/share/stegavorto
	${INSTALL_DATA} ${WRKSRC}/data/* \
		${DESTDIR}${PREFIX}/share/stegavorto/data

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
