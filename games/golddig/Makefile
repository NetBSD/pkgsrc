# $NetBSD: Makefile,v 1.1 1998/07/26 22:13:16 frueauf Exp $
#

DISTNAME=	golddig2
PKGNAME=	golddig-2.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://uiarchive.cso.uiuc.edu/pub/systems/linux/sunsite/games/arcade/

MAINTAINER=	root@garbled.net

USE_X11=	yes

post-extract:
	${RM} ${WRKSRC}/golddig ${WRKSRC}/makelev ${WRKSRC}/*.o

.include "../../mk/bsd.pkg.mk"
.if (${OBJECT_FMT} == "ELF")
RPATH=		-Wl,-rpath,${PREFIX}/lib
.endif
MAKE_ENV+=	RPATH=${RPATH}
