# $NetBSD: Makefile,v 1.10 2006/07/25 22:12:38 minskim Exp $
#

DISTNAME=	mercurial-0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.selenic.com/mercurial/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.selenic.com/mercurial/wiki/index.cgi/Mercurial
COMMENT=	Fast, lightweight source control management system

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_ACCEPTED=	24 23

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mercurial
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/mercurial
	${INSTALL_DATA} ${WRKSRC}/comparison.txt  ${PREFIX}/share/doc/mercurial

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
