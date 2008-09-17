# $NetBSD: Makefile,v 1.7 2008/09/17 01:18:42 bjs Exp $
#

PKGNAME=		scmgit-docs-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (documentation)

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		../../devel/scmgit-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

BUILD_TARGET=		doc

USE_LANGUAGES=		c
INSTALL_TARGET=		install-doc

.include "../../devel/scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
