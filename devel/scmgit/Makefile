# $NetBSD: Makefile,v 1.22 2007/12/12 04:11:29 bjs Exp $

.include "Makefile.common"

DISTNAME=	# empty
PKGNAME=	scmgit-${GIT_VERSION}
CATEGORIES+=	meta-pkgs
DISTFILES=	# empty

MAINTAINER=	bjs@NetBSD.org
COMMENT=	GIT version control suite meta-package

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs

AUTO_MKDIRS=		no
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
PLIST_SRC=		# empty (meta-package)

do-patch:

do-install:

.include "../../mk/bsd.pkg.mk"
