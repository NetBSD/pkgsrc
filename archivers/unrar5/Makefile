# $NetBSD: Makefile,v 1.1 2024/03/18 11:34:38 nia Exp $

.include "Makefile.common"

INSTALLATION_DIRS=	bin share/doc/unrar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${DESTDIR}${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
