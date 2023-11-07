# $NetBSD: Makefile,v 1.6 2023/11/07 22:38:02 wiz Exp $

DISTNAME=	gyb-1.71
PKGREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_GITHUB:=GAM-team/}
GITHUB_PROJECT=	got-your-back
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GAM-team/got-your-back
COMMENT=	Command line tool for backing up Gmail
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=2.0:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.11.2:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-httplib2-[0-9]*:../../security/py-google-auth-httplib2
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib>=0.4.1:../../security/py-google-auth-oauthlib

NO_BUILD=	yes
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
REPLACE_PYTHON=	*.py

INSTALLATION_DIRS=	bin ${PYSITELIB}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-install
SUBST_MESSAGE.config=	Setting config directory
SUBST_FILES.config=	gyb.py
SUBST_SED.config=	-e 's:PKG_SYSCONFDIR:${PKG_SYSCONFDIR}:'

PKG_SYSCONFSUBDIR=	gyb

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-install:
	cd ${WRKSRC};								\
	${INSTALL_SCRIPT} gyb.py ${DESTDIR}${PREFIX}/bin/gyb;			\
	for f in fmbox.py labellang.py; do					\
		${INSTALL_SCRIPT} $${f} ${DESTDIR}${PREFIX}/${PYSITELIB}/$${f};	\
	done

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
