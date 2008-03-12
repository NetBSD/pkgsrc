# $NetBSD: Makefile,v 1.1.1.1 2008/03/12 09:47:58 wiz Exp $
#

DISTNAME=	bash-completion-20060301
CATEGORIES=	shells
MASTER_SITES=	http://www.caliban.org/files/bash/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.caliban.org/bash/index.shtml
COMMENT=	Programmable completion specifications for bash

USE_TOOLS+=	bash:run

WRKSRC=		${WRKDIR}/bash_completion
USE_LANGUAGES=	# none

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bash-completion
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bash-completion
	${INSTALL_DATA_DIR} ${PREFIX}/share/bash-completion
	${INSTALL_DATA} ${WRKSRC}/bash* ${PREFIX}/share/bash-completion
	${INSTALL_DATA_DIR} ${PREFIX}/share/bash-completion/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/* \
		${PREFIX}/share/bash-completion/contrib

.include "../../mk/bsd.pkg.mk"
