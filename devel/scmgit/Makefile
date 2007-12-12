# $NetBSD: Makefile,v 1.23 2007/12/12 04:21:45 bjs Exp $

.include "Makefile.common"

DISTNAME=	# empty
PKGNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs
DISTFILES=	# empty

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs

NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_PATCH=		yes
NO_BUILD=		yes

PLIST_SRC=		# empty (meta-package)

do-install:

.include "../../mk/bsd.pkg.mk"
