# $NetBSD: Makefile,v 1.53 2014/07/16 18:25:08 tron Exp $

VERSION_DATE=	2014.07.15
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//S/.//}
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rg3.github.io/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/youtube-dl
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		BASHCOMPDIR=${PREFIX}/share/bash-completion/completions
INSTALLATION_DIRS=	share/youtube-dl
CHECK_INTERPRETER_SKIP=	share/youtube-dl/youtube-dl

post-patch:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/youtube-dl.sh
	${ECHO} 'exec ${PYTHONBIN} ${PREFIX}/share/youtube-dl/youtube-dl "$$@"' >> ${WRKSRC}/youtube-dl.sh

post-install:
	mv ${DESTDIR}${PREFIX}/bin/youtube-dl ${DESTDIR}${PREFIX}/share/youtube-dl
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl.sh ${DESTDIR}${PREFIX}/bin/youtube-dl

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
