# $NetBSD: Makefile,v 1.1 2013/09/09 13:56:27 wiz Exp $

.include "../../devel/git/Makefile.version"

DISTNAME=	# empty
PKGNAME=	git-${GIT_VERSION}
CATEGORIES+=	meta-pkgs devel
DISTFILES=	# empty
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GIT version control suite meta-package

META_PACKAGE=	yes

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	git-docs>=${GIT_VERSION}:../../devel/git-docs
DEPENDS+=	git-gitk>=${GIT_VERSION}:../../devel/git-gitk

.include "../../mk/bsd.pkg.mk"
