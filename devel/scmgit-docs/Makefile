# $NetBSD: Makefile,v 1.6 2008/04/21 01:09:51 bjs Exp $
#

PKGNAME=		scmgit-docs-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (documentation)

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../scmgit-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

BUILD_TARGET=		doc

USE_LANGUAGES=		c
INSTALL_TARGET=		install-doc

.include "${.CURDIR}/../scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
