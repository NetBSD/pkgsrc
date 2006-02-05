# $NetBSD: Makefile,v 1.11 2006/02/05 23:08:27 joerg Exp $
#

DISTNAME=	zephyr-mode-2.5.20
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	CMU Emacs-based Zephyr client

DEPENDS+=	tzc>=2.6.15:../../chat/tzc

NO_BUILD=	yes

.include "../../mk/emacs.mk"

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/zephyr-mode
	@for f in ${WRKSRC}/elisp/*.el; do \
		j="${INSTALL_DATA} $$f ${EMACS_LISPPREFIX}/zephyr-mode"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
