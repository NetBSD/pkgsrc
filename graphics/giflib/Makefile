# $NetBSD: Makefile,v 1.16 1999/09/30 15:21:55 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/09/24 06:55:01 tg Exp
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/giflib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ccil.org/~esr/giflib/

USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CC="${CC} -I${LOCALBASE}/include"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/gif2x11.html

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.txt \
	  ${PREFIX}/share/doc/giflib

.include "../../mk/bsd.pkg.mk"
