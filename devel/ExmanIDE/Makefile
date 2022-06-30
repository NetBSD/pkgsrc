# $NetBSD: Makefile,v 1.35 2022/06/30 11:18:10 nia Exp $

DISTNAME=	ExmanIDE-0.9.4
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	http://kldp.net/download.php/715/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://exmanide.kldp.net/
COMMENT=	Integrated development environment for Python

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/${PKGBASE}
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	27 # py-wxWidgets

SUBST_CLASSES+=		mod
SUBST_MESSAGE.mod=	Fixing deprecated module names.
SUBST_STAGE.mod=	pre-configure
SUBST_FILES.mod=	Profile.py SourceEditor.py
SUBST_SED.mod=		-e 's,wxPython\.lib\.PyCrust,wxPython.py,g'
SUBST_SED.mod+=		-e 's,wxPython\.py,wx.py,g'

SUBST_CLASSES+=		py
SUBST_MESSAGE.py=	Fixing paths in a wrapper script.
SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		ExmanIDE
SUBST_SED.py=		-e 's,python \$$0\.pyw,${PYTHONBIN} ${PREFIX}/share/${PKGBASE}/ExmanIDE.pyw,g'

SUBST_CLASSES+=		py2
SUBST_MESSAGE.py2=	Fixing path in Python module.
SUBST_STAGE.py2=	pre-configure
SUBST_FILES.py2=	ExmanIDE.pyw
SUBST_SED.py2=		-e 's,/usr/bin/env python.*$$,${PYTHONBIN},'

INSTALLATION_DIRS=	bin share/ExmanIDE

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ExmanIDE ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rwppm '-s|.*/CVS.*$$||'	\
		'-s|.*/ExmanIDE$$||' '-s|.*/.xvpics.*$$||' \
		. ${DESTDIR}${PREFIX}/share/ExmanIDE
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/share/ExmanIDE
	${PY_COMPILE_O_ALL} ${DESTDIR}${PREFIX}/share/ExmanIDE

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
