# $NetBSD: Makefile,v 1.2 2008/12/11 22:45:46 wiz Exp $
#

DISTNAME=	stegavorto-src-2008.12.11
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	http://hamsterrepublic.com/games/stegavorto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://james.hamsterrepublic.com/?p=130
COMMENT=	Discover secret messages embedded in the works of great authors

WRKSRC=		${WRKDIR}/stegavorto-src
USE_LANGUAGES=	# none

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

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
