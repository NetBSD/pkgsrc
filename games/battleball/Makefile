# $NetBSD: Makefile,v 1.16 2004/11/13 22:04:52 jlam Exp $

DISTNAME=	battleball.21.src
PKGNAME=	battleball-2.1
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://linuxberg.prover.com.br/files/x11/entertain/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.cs.utexas.edu/users/pahardin/bb.html
COMMENT=	3d game of soccer, with tanks

WRKSRC=		${WRKDIR}/battleball-2.1-src
USE_BUILDLINK3=	YES
USE_X11=	YES
USE_LANGUAGES=	c c++

SED_CMDS=	-e '/^INCS/s|$$|${CPPFLAGS}|' -e '/^LIBS/s|$$|${LDFLAGS}|'

do-configure:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig; \
	${SED} ${SED_CMDS} < ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin/

.include "../../mk/bsd.prefs.mk"

.if defined(BATTLEBALL_USE_MESA)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CPPFLAGS+=	-DNO_OPENGL
SED_CMDS+=	-e '/^GLINCS/s|^|\#|' -e '/^GLLIBS/s|^|\#|'
.endif

.include "../../mk/bsd.pkg.mk"
