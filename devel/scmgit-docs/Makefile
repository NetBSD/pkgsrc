# $NetBSD: Makefile,v 1.13 2012/09/28 17:34:18 apb Exp $

PKGNAME=	scmgit-docs-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (documentation)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		git<4.9.5nb1		# misc/git

DISTINFO_FILE=		../../devel/scmgit-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=		c
BUILD_TARGET=		man
INSTALL_TARGET=		install-man

UNLIMIT_RESOURCES+=	datasize

USE_TOOLS+=             perl:run
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

.include "../../devel/scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
