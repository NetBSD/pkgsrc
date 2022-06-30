# $NetBSD: Makefile,v 1.7 2022/06/30 11:18:17 nia Exp $
#

DISTNAME=	PythonTidy-1.20
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://lacusveris.com/PythonTidy/
EXTRACT_SUFX=	.python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lacusveris.com/PythonTidy/
COMMENT=	Cleans up, regularizes, and reformats the text of Python scripts
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

REPLACE_PYTHON=			${WRKSRC}/*.py
SUBST_CLASSES+=			pythonbin
SUBST_STAGE.pythonbin=		pre-configure
SUBST_MESSAGE.pythonbin=	Fixing references to python interpreter.
SUBST_FILES.pythonbin=		*.py
SUBST_SED.pythonbin=		-e 's,%PYTHONBIN%,${PYTHONBIN},g'

do-extract:
	${MKDIR} ${WRKSRC:Q}
	${CP} ${_DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX:Q} \
	    ${WRKSRC:Q}/pythontidy.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/pythontidy.py \
	    ${DESTDIR}${PREFIX}/bin/pythontidy

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
