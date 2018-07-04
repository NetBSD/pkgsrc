# $NetBSD: Makefile,v 1.9 2018/07/04 13:40:25 jperkin Exp $

DISTNAME=	vimpager-1.8.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkitover/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://www.vim.org/scripts/script.php?script_id=1723
COMMENT=	Use ViM as PAGER
LICENSE=	2-clause-bsd

DEPENDS+=	vim{,-gtk2,-gtk3,-motif,-xaw}>=7.0:../../editors/vim

NO_BUILD=	yes

USE_TOOLS+=	sh:run bash:run

SUBST_CLASSES+=		vimpager
SUBST_STAGE.vimpager=	pre-configure
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
