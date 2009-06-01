# $NetBSD: Makefile,v 1.2 2009/06/01 17:37:58 tonnerre Exp $
#

DISTNAME=		patchadd-0.1.1-durchstich
PKGNAME=		patchadd-0.1.1ds
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/misc/tonnerre/patchadd/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://oss.sygroup.ch/project/patchadd/
COMMENT=		Binary patch management tools
LICENSE=		original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		basename ftp

DEPENDS+=		bsdiff-[0-9]*:../../misc/bsdiff

GNU_CONFIGURE=		YES

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	post-configure
SUBST_FILES.tools=	patch_add patch_delete patch_info
SUBST_SED.tools=	-e "s|${TOOLS_DIR}/bin/ftp|${FTP}|g"
SUBST_SED.tools+=	-e "s|${TOOLS_DIR}/bin/basename|${BASENAME}|g"
SUBST_SED.tools+=	-e "s|${TOOLS_DIR}/bin/mkdir|${MKDIR:S/-p//}|g"

CONFIGURE_ARGS+=	--localstatedir=/var

.include "../../mk/bsd.pkg.mk"
