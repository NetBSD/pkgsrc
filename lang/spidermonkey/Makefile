# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:51 joerg Exp $
#

DISTNAME=	js-1.5
PKGNAME=	${DISTNAME:S/js/spidermonkey/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/js/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/js/spidermonkey/
COMMENT=	Standalone JavaScript implementation in C

WRKSRC=		${WRKDIR}/js/src

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKEFILE=	Makefile.ref

INSTALLATION_DIRS=	bin include lib

DIST_HEADERS=	jsapi.h jsautocfg.h jscompat.h jslong.h	\
	       	jsosdep.h jsotypes.h jspubtd.h jstypes.h

post-extract:
	${CP} ${FILESDIR}/pkgsrc.mk ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgsrc_DBG.OBJ/js ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/pkgsrc_DBG.OBJ/libjs.so ${PREFIX}/lib
	${CP} ${WRKSRC}/pkgsrc_DBG.OBJ/jsautocfg.h ${WRKSRC}
.for f in ${DIST_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/include
.endfor

.include "../../mk/bsd.pkg.mk"
