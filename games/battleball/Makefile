# $NetBSD: Makefile,v 1.23 2007/02/02 17:43:02 joerg Exp $

DISTNAME=	battleball.21.src
PKGNAME=	battleball-2.1
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://linuxberg.prover.com.br/files/x11/entertain/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://web.archive.org/web/*/http://www.cs.utexas.edu/users/pahardin/bb.html
COMMENT=	3d game of soccer, with tanks

WRKSRC=		${WRKDIR}/battleball-2.1-src
USE_LANGUAGES=	c c++

SED_CMDS=	-e '/^INCS/s|$$|${CPPFLAGS}|' -e '/^LIBS/s|$$|${LDFLAGS}|'

.include "options.mk"

INSTALLATION_DIRS=	bin

do-configure:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig; \
	${SED} ${SED_CMDS} < ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
