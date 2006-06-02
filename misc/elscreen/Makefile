# $NetBSD: Makefile,v 1.6 2006/06/02 13:51:48 uebayasi Exp $
#

DISTNAME=	elscreen-1.4.3
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.morishima.net/pub/morishima.net/naoto/ElScreen/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.morishima.net/~naoto/j/software/elscreen/
COMMENT=	Window manager within Emacs

.include "../../mk/emacs.mk"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel-[0-9]*:../../devel/apel
.endif

NO_BUILD=	yes

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/elscreen
	@${INSTALL_DATA} ${WRKSRC}/elscreen.el ${EMACS_LISPPREFIX}/elscreen
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/elscreen

.include "../../mk/bsd.pkg.mk"
