# $NetBSD: Makefile,v 1.6 2016/02/15 12:39:21 mef Exp $

DISTNAME=	vimpager-1.8.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkitover/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	http://www.vim.org/scripts/script.php?script_id=1723
COMMENT=	Use ViM as PAGER
LICENSE=	2-clause-bsd

DEPENDS+=	vim{,-gtk,-gtk2,-motif,-xaw}>=7.0:../../editors/vim

NO_BUILD=	yes

USE_TOOLS+=	sh:run bash:run

SUBST_CLASSES+=		vimpager
SUBST_STAGE.vimpager=	post-patch
SUBST_FILES.vimpager=	vimpager
SUBST_SED.vimpager=	-e 's,/usr/local/etc/,${PKG_SYSCONFDIR}/,g'

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-install
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,/share/man/,/${PKGMANDIR}/,g'

CONF_FILES+=		share/examples/vimpager/vimpagerrc ${PKG_SYSCONFDIR}/vimpagerrc

REPLACE_BASH+=		vimcat
REPLACE_SH+=		vimpager

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${PREFIX}/share/examples/vimpager

.include "../../mk/bsd.pkg.mk"
