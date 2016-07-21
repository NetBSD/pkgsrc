# $NetBSD: Makefile,v 1.9 2016/07/21 13:12:25 wiz Exp $

PKGNAME=	git-docs-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (documentation)

CONFLICTS+=		scmgit-docs-[0-9]*
SUPERSEDES+=		scmgit-docs-[0-9]*

DISTINFO_FILE=		../../devel/git-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=		c
BUILD_TARGET=		man
INSTALL_TARGET=		install-man

UNLIMIT_RESOURCES+=	datasize

USE_TOOLS+=             perl
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

.include "../../devel/git/Makefile.common"

.include "../../mk/bsd.pkg.mk"
