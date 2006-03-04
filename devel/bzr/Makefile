# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:12 jlam Exp $
#

DISTNAME=		bzr-0.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.bazaar-ng.org/pkg/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
