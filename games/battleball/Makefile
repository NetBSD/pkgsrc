# $NetBSD: Makefile,v 1.5 2000/10/15 12:06:34 rh Exp $

DISTNAME=	battleball.21.src
PKGNAME=	battleball-2.1
CATEGORIES=	games x11
MASTER_SITES=	http://linuxberg.prover.com.br/files/x11/entertain/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.cs.utexas.edu/users/pahardin/bb.html

USE_X11=	YES
WRKSRC=		${WRKDIR}/battleball-2.1-src

CPPFLAGS+=	-I${X11BASE}/include
SED_CMDS=	-e '/^INCS/s|$$|${CPPFLAGS}|' -e '/^LIBS/s|$$|${LDFLAGS}|'

do-configure:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig; \
	${SED} ${SED_CMDS} < ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin/

.include "../../mk/bsd.prefs.mk"

.if defined(BATTLEBALL_USE_MESA)
USE_MESA=	YES
.else
CPPFLAGS+=	-DNO_OPENGL
SED_CMDS+=	-e '/^GLINCS/s|^|\#|' -e '/^GLLIBS/s|^|\#|'
.endif

.include "../../mk/bsd.pkg.mk"
