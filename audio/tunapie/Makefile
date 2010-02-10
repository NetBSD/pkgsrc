# $NetBSD: Makefile,v 1.7 2010/02/10 19:17:33 joerg Exp $
#

DISTNAME=	tunapie-2.1.6
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tunapie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tunapie.sourceforge.net/
COMMENT=	Directory browser for Internet radio and TV streams

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_LANGUAGES=	# none
PYTHON_PATCH_SCRIPTS=		src/*.py
PY_PATCHPLIST=			yes

INSTALLATION_DIRS=	bin share/tunapie ${PKGMANDIR}/man1

do-install:
	${PYTHONBIN} ${WRKSRC}/src/compile
	${INSTALL_SCRIPT} ${WRKSRC}/src/*.py* ${DESTDIR}${PREFIX}/share/tunapie/
	${INSTALL_DATA} ${WRKSRC}/src/*.xpm ${DESTDIR}${PREFIX}/share/tunapie/
	${INSTALL_DATA} ${WRKSRC}/src/*.png ${DESTDIR}${PREFIX}/share/tunapie/
	${INSTALL_MAN} ${WRKSRC}/tunapie.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${ECHO} "#!/bin/sh" > ${WRKSRC}/tunapie.sh
	${ECHO} "${PYTHONBIN} ${PREFIX}/share/tunapie/Tunapie.py" >> \
		${WRKSRC}/tunapie.sh
	${INSTALL_SCRIPT} ${WRKSRC}/tunapie.sh ${DESTDIR}${PREFIX}/bin/tunapie

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
