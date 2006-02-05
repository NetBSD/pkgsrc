# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:08 joerg Exp $
#

DISTNAME=	elscreen-1.4.3
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.morishima.net/~naoto/j/software/elscreen/
COMMENT=	Window manager within Emacs

NO_BUILD=	yes

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/elscreen
	@${INSTALL_DATA} ${WRKSRC}/elscreen.el ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/elscreen

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
