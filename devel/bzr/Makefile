# $NetBSD: Makefile,v 1.1.1.1 2006/01/15 00:22:12 wiz Exp $
#

DISTNAME=		bzr-0.6.2
CATEGORIES=		devel
MASTER_SITES=		http://www.bazaar-ng.org/pkg/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.bazaar-ng.org/
COMMENT=		Open source distributed version control system (Bazaar-NG)

PY_PATCHPLIST=          yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	24

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bzr
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt  ${PREFIX}/share/doc/bzr
	${INSTALL_DATA} ${WRKSRC}/tutorial.txt  ${PREFIX}/share/doc/bzr

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
