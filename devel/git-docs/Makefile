# $NetBSD: Makefile,v 1.23 2025/01/14 21:41:39 adam Exp $

PKGNAME=	git-docs-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (documentation)

CONFLICTS+=	scmgit-docs-[0-9]*
SUPERSEDES+=	scmgit-docs-[0-9]*

TOOL_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
BUILD_TARGET=		man
INSTALL_TARGET=		install-man

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/git/Makefile.common"

.include "../../mk/bsd.pkg.mk"
