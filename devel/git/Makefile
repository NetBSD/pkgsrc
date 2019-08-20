# $NetBSD: Makefile,v 1.6 2019/08/20 13:00:02 adam Exp $

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
DEPENDS+=	git-contrib>=${GIT_VERSION}:../../devel/git-contrib
DEPENDS+=	git-docs>=${GIT_VERSION}:../../devel/git-docs

.include "../../mk/bsd.pkg.mk"
