# $NetBSD: Makefile,v 1.24 2008/01/05 11:10:18 rillig Exp $

.include "Makefile.common"

DISTNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
