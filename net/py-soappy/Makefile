# $NetBSD: Makefile,v 1.1.1.1 2002/10/01 17:21:39 drochner Exp $
#

DISTNAME=	SOAPpy097
PKGNAME=	${PYPKGPREFIX}-SOAPpy-0.9.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

NO_BUILD=	#yes
PY_PATCHPLIST=	#yes

# XXX hack to get rid of RCS keywords in patch files
post-extract:
	${SED} 's@\$$\(Id:.*\)\$$@\1@g' <${WRKSRC}/SOAP.py \
		>${WRKSRC}/SOAP.py.tmp
	${MV} ${WRKSRC}/SOAP.py.tmp ${WRKSRC}/SOAP.py

do-install:
	${CP} ${WRKSRC}/SOAP.py ${PREFIX}/${PYSITELIB}

.include "../../textproc/pyxml/buildlink.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
