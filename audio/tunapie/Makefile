# $NetBSD: Makefile,v 1.3 2009/02/09 22:56:21 joerg Exp $
#

DISTNAME=	tunapie-2.1.6
PKGREVISION=		1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tunapie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tunapie.sourceforge.net/
COMMENT=	Directory browser for Internet radio and TV streams

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_LANGUAGES=	# none
PYTHON_PATCH_SCRIPTS=		src/*.py
PY_PATCHPLIST=			yes

INSTALLATION_DIRS=	bin share/tunapie ${PKGMANDIR}/man1

do-install:
	${PYTHONBIN} ${WRKSRC}/src/compile
	${INSTALL_SCRIPT} ${WRKSRC}/src/*.py* ${PREFIX}/share/tunapie/
	${INSTALL_DATA} ${WRKSRC}/src/*.xpm ${PREFIX}/share/tunapie/
	${INSTALL_DATA} ${WRKSRC}/src/*.png ${PREFIX}/share/tunapie/
	${INSTALL_MAN} ${WRKSRC}/tunapie.1 ${PREFIX}/${PKGMANDIR}/man1
	${ECHO} "#!/bin/sh" > ${WRKSRC}/tunapie.sh
	${ECHO} "${PYTHONBIN} ${PREFIX}/share/tunapie/Tunapie.py" >> \
		${WRKSRC}/tunapie.sh
	${INSTALL_SCRIPT} ${WRKSRC}/tunapie.sh ${PREFIX}/bin/tunapie

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
