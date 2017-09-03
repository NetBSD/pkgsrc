# $NetBSD: Makefile,v 1.37 2017/09/03 08:53:08 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-idle-${PY_DISTVERSION}
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/idle/
COMMENT=	IDLE - The Integrated DeveLopment Environment for Python

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PY_PATCHPLIST=	yes

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

#
# With Python-2.3 and up, the Idle code is part of the base library.
# We just install a wrapper script. Also, threads are required now.
# NOTE: if you add a new version of Python here, add to the following test
#
.include "../../lang/python/extension.mk"

.if ${_PYTHON_VERSION} >= 31
IDLE_NAME=	idle3
.else
IDLE_NAME=	idle
.endif

EXTRACT_ELEMENTS=	${PYSUBDIR}/Tools/scripts/${IDLE_NAME}
REPLACE_PYTHON= Tools/scripts/${IDLE_NAME}
NO_BUILD=	yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Tools/scripts/${IDLE_NAME} \
		${DESTDIR}${PREFIX}/bin/idle${PYVERSSUFFIX}

.include "../../lang/python/srcdist.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
