# $NetBSD: Makefile,v 1.3 2010/05/26 19:50:00 gls Exp $
#

VERSION=		0.9.0
DISTNAME=		Fabric-${VERSION}
PKGNAME=		${DISTNAME:S/F/f/}
CATEGORIES=		sysutils net
MASTER_SITES=		http://code.fabfile.org/projects/fabric/files/

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		http://code.fabfile.org/projects/fabric
COMMENT=		Simple Pythonic remote deployment tool
LICENSE=		2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-paramiko>=1.7:../../security/py-paramiko

USE_TOOLS+=		pax

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/fabric
INSTALLATION_DIRS+=	share/doc/fabric/api
INSTALLATION_DIRS+=	share/doc/fabric/api/contrib
INSTALLATION_DIRS+=	share/doc/fabric/api/core
INSTALLATION_DIRS+=	share/doc/fabric/changes
INSTALLATION_DIRS+=	share/doc/fabric/usage

post-extract:
	${RM} -r ${WRKSRC}/paramiko

post-install:
	${INSTALL_MAN} files/fab.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

	cd ${WRKSRC}/docs && pax -wr -pma *.rst api/contrib/*.rst \
		api/core/*.rst changes/* usage/* \
		${DESTDIR}${PREFIX}/share/doc/fabric/.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
