# $NetBSD: Makefile,v 1.4 2006/08/22 18:24:22 wiz Exp $
#

DISTNAME=		tailor-0.9.26
CATEGORIES=		devel
MASTER_SITES=		http://darcs.arstecnica.it/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.darcs.net/DarcsWiki/Tailor
COMMENT=		Tool to migrate changesets between various version control systems

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	24 23

PYTHON_PATCH_SCRIPTS=	tailor

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tailor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tailor

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
