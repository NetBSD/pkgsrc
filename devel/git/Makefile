# $NetBSD: Makefile,v 1.2 2013/09/11 01:26:00 obache Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GIT version control suite meta-package

SUPERSEDES+=	scmgit-[0-8]*

META_PACKAGE=	yes

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	git-docs>=${GIT_VERSION}:../../devel/git-docs
DEPENDS+=	git-gitk>=${GIT_VERSION}:../../devel/git-gitk

.include "../../mk/bsd.pkg.mk"
