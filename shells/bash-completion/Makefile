# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:35 joerg Exp $
#

DISTNAME=	bash-completion-20060301
CATEGORIES=	shells
MASTER_SITES=	http://www.caliban.org/files/bash/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.caliban.org/bash/index.shtml
COMMENT=	Programmable completion specifications for bash

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run

WRKSRC=		${WRKDIR}/bash_completion
USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	share/bash-completion/contrib share/doc/bash-completion

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bash-completion
	${INSTALL_DATA} ${WRKSRC}/bash* ${DESTDIR}${PREFIX}/share/bash-completion
	${INSTALL_DATA} ${WRKSRC}/contrib/* \
	    ${DESTDIR}${PREFIX}/share/bash-completion/contrib

.include "../../mk/bsd.pkg.mk"
