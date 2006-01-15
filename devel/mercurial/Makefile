# $NetBSD: Makefile,v 1.1.1.1 2006/01/15 02:15:58 wiz Exp $
#

DISTNAME=		mercurial-0.7
CATEGORIES=		devel
MASTER_SITES=		http://www.selenic.com/mercurial/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.selenic.com/mercurial/wiki/index.cgi/Mercurial
COMMENT=		Fast, lightweight source control management system


PY_PATCHPLIST=          yes
PYDISTUTILSPKG=		yes

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
