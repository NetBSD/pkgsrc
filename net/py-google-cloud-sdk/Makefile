# $NetBSD: Makefile,v 1.5 2020/11/23 06:11:17 riastradh Exp $

GCLOUDVER=	319.0.0
DISTNAME=	google-cloud-sdk-${GCLOUDVER}-linux-x86
PKGNAME=	${PYPKGPREFIX}-google-cloud-sdk-${GCLOUDVER}
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://cloud.google.com/sdk/
COMMENT=	Google Cloud SDK (for Compute Engine etc.)
LICENSE=	apache-2.0

GCSWRKSUBDIR=	google-cloud-sdk
WRKSRC=		${WRKDIR}/${GCSWRKSUBDIR}
NO_BUILD=	yes

USE_TOOLS+=	pax

REPLACE_PYTHON+=	bin/*
REPLACE_PYTHON+=	bin/bootstrapping/*

PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Replacing hard coded python executable name
SUBST_FILES.python=	lib/googlecloudsdk/core/*
SUBST_FILES.python+=	bin/*
SUBST_SED.python=	-e "s,CLOUDSDK_PYTHON=..*,CLOUDSDK_PYTHON=${PYTHONBIN},"

INSTALLATION_DIRS=	${PKGBASE}

do-install:
	cd ${WRKDIR} && \
		${FIND} ${GCSWRKSUBDIR} -type d -exec chmod 755 {} \;
	cd ${WRKDIR} && \
		${FIND} ${GCSWRKSUBDIR} -type f -exec chmod 644 {} \;
	cd ${WRKDIR} && \
		${FIND} ${GCSWRKSUBDIR}/bin -type f -exec chmod 755 {} \;
	cd ${WRKDIR}/${GCSWRKSUBDIR} && \
		${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
