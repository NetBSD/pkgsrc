# $NetBSD: Makefile,v 1.73 2014/11/23 12:35:19 adam Exp $

.include "Makefile.common"

INSTALLATION_DIRS=	bin share/doc/unrar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${DESTDIR}${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
