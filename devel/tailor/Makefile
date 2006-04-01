# $NetBSD: Makefile,v 1.1.1.1 2006/04/01 06:54:32 wiz Exp $
#

DISTNAME=		tailor-0.9.20
CATEGORIES=		devel
MASTER_SITES=		http://darcs.arstecnica.it/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.darcs.net/DarcsWiki/Tailor
COMMENT=		Tool to migrate changesets between various version control systems

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	24 23

PYTHON_PATCH_SCRIPTS=	tailor

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
