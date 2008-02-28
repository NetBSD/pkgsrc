# $NetBSD: Makefile,v 1.4 2008/02/28 15:11:29 bjs Exp $
#

PKGNAME=		scmgit-docs-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (documentation)

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../scmgit-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

BUILD_TARGET=		doc

USE_LANGUAGES=		# none
INSTALL_TARGET=		install-doc

.include "${.CURDIR}/../scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
