# $NetBSD: Makefile,v 1.3 2019/10/01 14:45:29 nia Exp $

DISTNAME=	pydicom-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=pydicom/}
GITHUB_PROJECT=	pydicom
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	eborisch@gmail.com
HOMEPAGE=	https://github.com/pydicom/pydicom/
COMMENT=	Pure python package for working with DICOM files
LICENSE=	modified-bsd AND mit

USE_LANGUAGES=	# none

DOCDIR=			share/doc/${PKGBASE}
PLIST_SUBST+=		DOCDIR=${DOCDIR:Q}
INSTALLATION_DIRS+=	${DOCDIR}

post-extract:
	${CHMOD} a-x ${WRKSRC}/pydicom/data/test_files/*.dcm

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
