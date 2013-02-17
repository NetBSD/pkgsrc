# $NetBSD: Makefile,v 1.6 2013/02/17 19:18:00 dholland Exp $
#

DISTNAME=	php-mode-1.5.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=php-mode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/php-mode/
COMMENT=	PHP editing mode for Emacs

NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile php-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/php-mode
	${INSTALL_DATA} ${WRKSRC}/php-mode.e* \
		${DESTDIR}${EMACS_LISPPREFIX}/php-mode

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
