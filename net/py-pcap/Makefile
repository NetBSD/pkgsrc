# $NetBSD: Makefile,v 1.13 2019/04/26 13:14:10 maya Exp $

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
SUBST_STAGE.python=	pre-configure

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.prefix=	pre-configure

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-pyrex

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
