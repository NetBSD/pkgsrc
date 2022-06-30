# $NetBSD: Makefile,v 1.56 2022/06/30 11:18:50 nia Exp $

VERSION=		1.12.0
DISTNAME=		Fabric-${VERSION}
PKGNAME=		${DISTNAME:S/F/f/}
PKGREVISION=		5
CATEGORIES=		sysutils net
MASTER_SITES=		${MASTER_SITE_PYPI:=F/Fabric/}

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		http://fabfile.org/
COMMENT=		Simple Pythonic remote deployment tool
LICENSE=		2-clause-bsd

DEPENDS+=		${PYPKGPREFIX}-paramiko>=1.10.0:../../security/py-paramiko

PYTHON_VERSIONS_ACCEPTED=	27 # no support yet

USE_PKG_RESOURCES=	yes

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

	cd ${WRKSRC}/sites/docs && pax -wr -pma *.rst api/contrib/*.rst \
		api/core/*.rst usage/* \
		${DESTDIR}${PREFIX}/share/doc/fabric/.
	cd ${WRKSRC}/sites/www && pax -wr -pma *.rst \
		${DESTDIR}${PREFIX}/share/doc/fabric/.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
