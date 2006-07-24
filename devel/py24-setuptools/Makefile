# $NetBSD: Makefile,v 1.3 2006/07/24 22:51:32 wiz Exp $
#

DISTNAME=		setuptools-0.6c1-py2.4.egg
PKGNAME=		py24-setuptools-0.6c1
CATEGORIES=		devel
MASTER_SITES=		http://cheeseshop.python.org/packages/2.4/s/setuptools/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/DevCenter/setuptools
COMMENT=		New Python packaging system

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED= 24
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
TMPSCRIPT=	${WRKSRC}
INSTCMD=	import sys; \
		sys.path.insert(0,"${DISTNAME}"); \
		from setuptools.command.easy_install import main; \
		main(["-s", "${TMPSCRIPT}", "${DISTNAME}"])

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} -c ${INSTCMD:Q}
	${INSTALL_SCRIPT} ${TMPSCRIPT}/easy_install \
		${PREFIX}/bin/easy_install${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
