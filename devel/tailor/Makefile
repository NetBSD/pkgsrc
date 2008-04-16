# $NetBSD: Makefile,v 1.11 2008/04/16 08:47:27 wiz Exp $
#

DISTNAME=		tailor-0.9.31
CATEGORIES=		devel scm
MASTER_SITES=		http://darcs.arstecnica.it/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.darcs.net/DarcsWiki/Tailor
COMMENT=		Tool to migrate changesets between various version control systems

#LICENSE=		GPLv3
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	24 23

PYTHON_PATCH_SCRIPTS=	tailor

INSTALLATION_DIRS=	share/doc/tailor

post-install:
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/tailor

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
