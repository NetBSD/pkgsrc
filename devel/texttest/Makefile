# $NetBSD: Makefile,v 1.37 2025/02/21 16:12:58 schmonz Exp $

DISTNAME=		texttest-4.4.3.1
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=t/texttest/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://texttest.sourceforge.net/
COMMENT=		Tool for text-based Approval Testing
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=		${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools>=61.0:../../devel/py-setuptools

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	texttestlib/default/batch/__init__.py
REPLACE_PYTHON+=	texttestlib/default/virtualdisplay.py
REPLACE_PYTHON+=	texttestlib/log/logconfiggen_setup.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

WHEEL_NAME=		TextTest-${PKGVERSION_NOREV}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	texttestlib/default/__init__.py
SUBST_VARS.prefix=	PREFIX

post-extract:
	${FIND} ${WRKSRC} -type f -name '*cpython*.pyc' | ${XARGS} ${RM} -f

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.orig' | ${XARGS} ${RM} -f

.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
