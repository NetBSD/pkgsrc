# $NetBSD: Makefile,v 1.3 2003/01/02 18:39:13 wiz Exp $
#

DISTNAME=	zephyr-mode-2.5.20
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	CMU Emacs-based Zephyr client

DEPENDS=	tzc>=2.6.15:../../chat/tzc

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"
.include "../../mk/emacs.mk"

do-build:

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/zephyr-mode
	@for f in ${WRKSRC}/elisp/*.el; do \
		j="${INSTALL_DATA} $$f ${EMACS_LISPPREFIX}/zephyr-mode"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
