# $NetBSD: Makefile,v 1.3 2003/03/19 11:51:08 drochner Exp $
#

DISTNAME=	SOAPpy-0.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

USE_BUILDLINK2=	YES

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

post-install:
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py \
		${PREFIX}/${PYSITELIB}/SOAPpy

.include "../../textproc/pyxml/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
