# $NetBSD: Makefile,v 1.3 2014/01/07 14:59:04 wiz Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GIT version control suite meta-package
LICENSE=	gnu-gpl-v2

SUPERSEDES+=	scmgit-[0-9]*

META_PACKAGE=	yes

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	git-docs>=${GIT_VERSION}:../../devel/git-docs
DEPENDS+=	git-gitk>=${GIT_VERSION}:../../devel/git-gitk

.include "../../mk/bsd.pkg.mk"
