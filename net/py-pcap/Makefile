# $NetBSD: Makefile,v 1.10 2017/09/04 18:55:09 wiz Exp $

DISTNAME=	pypcap-1.1
PKGNAME=	${PYPKGPREFIX}-pcap-1.1
PKGREVISION=	1
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
SUBST_STAGE.python=	post-patch

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.prefix=	post-patch

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-pyrex

FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

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
