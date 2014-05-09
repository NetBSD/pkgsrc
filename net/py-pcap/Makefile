# $NetBSD: Makefile,v 1.5 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	pypcap-1.1
PKGNAME=	${PYPKGPREFIX}-pcap-1.1
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://pypcap.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pypcap/
COMMENT=	Simplified object-oriented python module for libpcap
LICENSE=	modified-bsd

BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

SUBST_CLASSES+=         python
SUBST_FILES.python=     Makefile
SUBST_SED.python+=      -e 's,@PYTHON@,${PYTHONBIN},g'
SUBST_STAGE.python=     post-patch
SUBST_CLASSES+=         prefix
SUBST_FILES.prefix=     Makefile
SUBST_SED.prefix=       -e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.prefix=     post-patch

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-pyrex

FILES_SUBST+=   PYTHONBIN=${PYTHONBIN:Q}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	pyrexc pcap.pyx

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config
	# --with-pcap=${PREFIX}

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
