# $NetBSD: Makefile,v 1.5 2019/07/17 14:33:28 gdt Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-${GIT_VERSION}
PKGREVISION=	1
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
