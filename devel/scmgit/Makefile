# $NetBSD: Makefile,v 1.26 2008/06/14 16:21:03 bjs Exp $

.include "../../devel/scmgit/Makefile.version"

DISTNAME=	# empty
PKGNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
