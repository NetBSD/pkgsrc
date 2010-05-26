# $NetBSD: Makefile,v 1.1.1.1 2010/05/26 18:26:20 gls Exp $
#

VERSION=		0.9.0
DISTNAME=		Fabric-${VERSION}
PKGNAME=		${DISTNAME:S/F/f/}
CATEGORIES=		www
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
#	${INSTALL_DATA} ${WRKSRC}/docs/*.rst \
#	  	${DESTDIR}${PREFIX}/share/doc/fabric
#	${INSTALL_DATA} ${WRKSRC}/docs/api/contrib/*.rst \
#	  	${DESTDIR}${PREFIX}/share/doc/fabric/api/contrib
#	${INSTALL_DATA} ${WRKSRC}/docs/api/core/*.rst \
#	  	${DESTDIR}${PREFIX}/share/doc/fabric/api/core
#	${INSTALL_DATA} ${WRKSRC}/docs/changes/* \
#		${DESTDIR}${PREFIX}/share/doc/fabric/changes
#	${INSTALL_DATA} ${WRKSRC}/docs/usage/* \
#	  	${DESTDIR}${PREFIX}/share/doc/fabric/usage
#
	cd ${WRKSRC}/docs && pax -wr -pma *.rst api/contrib/*.rst \
		api/core/*.rst changes/* usage/* \
		${DESTDIR}${PREFIX}/share/doc/fabric/.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
