# $NetBSD: Makefile,v 1.17 2022/01/22 14:35:52 wiz Exp $

DISTNAME=	pypcap-1.1
PKGNAME=	${PYPKGPREFIX}-pcap-1.1
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://pypcap.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/dugsong/pypcap
COMMENT=	Simplified object-oriented python module for libpcap
LICENSE=	modified-bsd

BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

SUBST_CLASSES+=		python
SUBST_FILES.python=	Makefile
SUBST_SED.python+=	-e 's,@PYTHON@,${PYTHONBIN},g'
SUBST_STAGE.python=	pre-configure

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_VARS.prefix=	PREFIX
SUBST_STAGE.prefix=	pre-configure

PYTHON_VERSIONS_ACCEPTED=	27 # py-pyrex
EGG_NAME=			pcap-${PKGVERSION_NOREV}

FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	pyrexc pcap.pyx

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config
	# --with-pcap=${PREFIX}

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
