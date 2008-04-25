# $NetBSD: Makefile,v 1.10 2008/04/25 20:39:08 joerg Exp $

DISTNAME=	ExmanIDE-0.9.4
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://kldp.net/download.php/715/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://exmanide.kldp.net/
COMMENT=	Integrated development environment for Python

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets

WRKSRC=		${WRKDIR}/${PKGBASE}
NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		mod
SUBST_MESSAGE.mod=	Fixing deprecated module names.
SUBST_STAGE.mod=	post-patch
SUBST_FILES.mod=	Profile.py SourceEditor.py StcStyle.py
SUBST_SED.mod=		-e 's,wxPython\.lib\.PyCrust,wxPython.py,g'	\
			-e 's,wxPython\.py,wx.py,g'

SUBST_CLASSES+=		py
SUBST_MESSAGE.py=	Fixing paths in a wrapper script.
SUBST_STAGE.py=		post-patch
SUBST_FILES.py=		ExmanIDE
SUBST_SED.py=		-e 's,python \$$0\.pyw,${PYTHONBIN} ${PREFIX}/share/${PKGBASE}/ExmanIDE.pyw,g'

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

INSTALLATION_DIRS=	 bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ExmanIDE ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}
	cd ${WRKSRC} && ${PAX} -rwppm '-s|.*/CVS.*$$||'	\
		'-s|.*/ExmanIDE$$||' '-s|.*/.xvpics.*$$||' \
		. ${PREFIX}/share/${PKGBASE}
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/share/${PKGBASE}
	${PYTHONBIN} -O ${PYCOMPILEALL} ${PREFIX}/share/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
