# $NetBSD: Makefile,v 1.1.1.1 2002/12/30 17:41:35 sommerfeld Exp $
#

DISTNAME=	zephyr-mode-2.5.20
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	CMU Emacs-based Zephyr client

DEPENDS=	tzc:../../net/tzc>2.6.15

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"
.include "../../mk/emacs.mk"

do-build:

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/zephyr-mode
	@for file in ${WRKSRC}/elisp/*.el; do \
		j="${INSTALL_DATA} $$file ${EMACS_LISPPREFIX}/zephyr-mode"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
