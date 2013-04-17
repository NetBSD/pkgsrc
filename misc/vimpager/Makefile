# $NetBSD: Makefile,v 1.1 2013/04/17 13:42:48 obache Exp $

DISTNAME=	vimpager-1.8.1
CATEGORIES=	misc
MASTER_SITES=	-http://nodeload.github.com/rkitover/vimpager/tar.gz/${PKGVERSION_NOREV}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	http://www.vim.org/scripts/script.php?script_id=1723
COMMENT=	Use ViM as PAGER
LICENSE=	2-clause-bsd

DEPENDS+=	vim{,-gtk,gtk2,-motif,-xaw}>=7.0:../../editors/vim

NO_BUILD=	yes

USE_TOOLS+=	sh:run bash:run

SUBST_CLASSES+=		vimpager
SUBST_STAGE.vimpager=	post-patch
SUBST_FILES.vimpager=	vimpager
SUBST_SED.vimpager=	-e 's,/usr/local/etc/,${PKG_SYSCONFDIR}/,g'

CONF_FILES+=		share/examples/vimpager/vimpagerrc ${PKG_SYSCONFDIR}/vimpagerrc

REPLACE_BASH+=		vimcat
REPLACE_SH+=		vimpager

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/vimpager

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vimcat ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vimpager ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vimpager.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/vimpagerrc ${DESTDIR}${PREFIX}/share/examples/vimpager

.include "../../mk/bsd.pkg.mk"
