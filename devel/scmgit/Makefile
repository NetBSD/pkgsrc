# $NetBSD: Makefile,v 1.25 2008/05/26 10:50:17 wiz Exp $

.include "Makefile.common"

PKGNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
