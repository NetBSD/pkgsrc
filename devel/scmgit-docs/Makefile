# $NetBSD: Makefile,v 1.8 2009/08/31 10:08:59 seb Exp $
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

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
