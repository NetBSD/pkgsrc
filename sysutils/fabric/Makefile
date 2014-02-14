# $NetBSD: Makefile,v 1.34 2014/02/14 19:59:57 gls Exp $

VERSION=		1.8.2
DISTNAME=		Fabric-${VERSION}
PKGNAME=		${DISTNAME:S/F/f/}
CATEGORIES=		sysutils net
MASTER_SITES=		http://pypi.python.org/packages/source/F/Fabric/

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		http://fabfile.org/
COMMENT=		Simple Pythonic remote deployment tool
LICENSE=		2-clause-bsd

FETCH_USING=		curl

DEPENDS+=		${PYPKGPREFIX}-paramiko>=1.10.0:../../security/py-paramiko

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-paramiko

USE_TOOLS+=		pax

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/fabric
INSTALLATION_DIRS+=	share/doc/fabric/api
INSTALLATION_DIRS+=	share/doc/fabric/api/contrib
INSTALLATION_DIRS+=	share/doc/fabric/api/core
INSTALLATION_DIRS+=	share/doc/fabric/changes
INSTALLATION_DIRS+=	share/doc/fabric/usage

post-install:
	${INSTALL_MAN} files/fab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

	cd ${WRKSRC}/docs && pax -wr -pma *.rst api/contrib/*.rst \
		api/core/*.rst usage/* \
		${DESTDIR}${PREFIX}/share/doc/fabric/.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
