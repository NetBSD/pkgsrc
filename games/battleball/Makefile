# $NetBSD: Makefile,v 1.20 2005/06/16 06:57:53 jlam Exp $

DISTNAME=	battleball.21.src
PKGNAME=	battleball-2.1
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://linuxberg.prover.com.br/files/x11/entertain/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.cs.utexas.edu/users/pahardin/bb.html
COMMENT=	3d game of soccer, with tanks

WRKSRC=		${WRKDIR}/battleball-2.1-src
USE_LANGUAGES=	c c++

SED_CMDS=	-e '/^INCS/s|$$|${CPPFLAGS}|' -e '/^LIBS/s|$$|${LDFLAGS}|'

.include "options.mk"

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-configure:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig; \
	${SED} ${SED_CMDS} < ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
