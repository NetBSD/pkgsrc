# $NetBSD: Makefile,v 1.21 2022/07/06 11:53:59 adam Exp $

PKGNAME=	git-docs-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (documentation)

CONFLICTS+=		scmgit-docs-[0-9]*
SUPERSEDES+=		scmgit-docs-[0-9]*

DISTINFO_FILE=		../../devel/git-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
BUILD_TARGET=		man
INSTALL_TARGET=		install-man

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/git/Makefile.common"

.include "../../mk/bsd.pkg.mk"
