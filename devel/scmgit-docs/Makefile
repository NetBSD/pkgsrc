# $NetBSD: Makefile,v 1.11 2010/10/28 11:11:00 adam Exp $

PKGNAME=		scmgit-docs-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (documentation)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		git<4.9.5nb1		# misc/git

DISTINFO_FILE=		../../devel/scmgit-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=		c
BUILD_TARGET=		man
INSTALL_TARGET=		install-man

UNLIMIT_RESOURCES+=	datasize

# our asciidoc doesn't handle {litdd} in titles
SUBST_CLASSES+=		litdd
SUBST_STAGE.litdd=	pre-configure
SUBST_MESSAGE.litdd=	Fixing {litdd} in text files.
SUBST_FILES.litdd=	Documentation/git-*--*.txt
SUBST_SED.litdd=	-e 's,{litdd},--,g'
SUBST_SED.litdd+=	-e 's,^=====,,g'

.include "../../devel/scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
