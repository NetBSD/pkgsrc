# $NetBSD: Makefile,v 1.2 2024/07/28 12:03:29 wiz Exp $

DISTNAME=	PyDPainter-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mriale/}
GITHUB_PROJECT=	PyDPainter
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mriale/PyDPainter/
COMMENT=	Usable pixel art paint program written in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/PyDPainter-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin share/py-DPainter

REPLACE_PYTHON=	*.py */*.py

do-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/PyDPainter.sh
	${ECHO} "cd ${PREFIX}/share/py-DPainter && ${PYTHONBIN} PyDPainter.py \""'$$@'"\"" >> ${WRKSRC}/PyDPainter.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/PyDPainter.sh ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${PAX} -pp -rw PyDPainter.py data iff_pics libs logo ${DESTDIR}${PREFIX}/share/py-DPainter

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
