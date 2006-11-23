# $NetBSD: Makefile,v 1.3.2.1 2006/11/23 09:41:31 ghen Exp $
#

DISTNAME=		setuptools-0.6c1-py2.4.egg
PKGNAME=		py24-setuptools-0.6c1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://cheeseshop.python.org/packages/2.4/s/setuptools/
EXTRACT_SUFX=		# empty

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/DevCenter/setuptools
COMMENT=		New Python packaging system

WRKSRC=		${WRKDIR}
PYTHON_VERSIONS_ACCEPTED= 24
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q} PYPKGPREFIX=${PYPKGPREFIX}
TMPSCRIPT=	${WRKSRC}
INSTCMD=	import sys; \
		sys.path.insert(0,"${DISTNAME}"); \
		from setuptools.command.easy_install import main; \
		main(["-s", "${TMPSCRIPT}", "${DISTNAME}"])

CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/easy-install.pth

FILES_SUBST+=	PYSITELIB=${PREFIX}/${PYSITELIB}

do-build:
	${SED} -e 's,@PYTHON@,${PYTHONBIN},' \
	       -e 's,@PYPREFIX@,${PYPKGPREFIX},' \
	       -e 's,@PYSITELIB@,${PREFIX}/${PYSITELIB},' \
	       ${FILESDIR}/manage-eggs.py > ${WRKSRC}/manage-eggs.py

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} -c ${INSTCMD:Q}
	${INSTALL_SCRIPT} ${TMPSCRIPT}/easy_install \
		${PREFIX}/bin/easy_install${PYVERSSUFFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/manage-eggs.py ${PREFIX}/bin/${PYPKGPREFIX}-manage-eggs

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
