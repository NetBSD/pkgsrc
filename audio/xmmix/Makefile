# $NetBSD: Makefile,v 1.11 1998/06/18 16:15:11 agc Exp $
# FreeBSD ID: Makefile,v 1.5 1997/09/08 13:37:47 tg Exp
#

DISTNAME=       xmmix-1.2
CATEGORIES=	audio
MASTER_SITES=   http://mercury.hypersurf.com/~amb/download/xmmix-1.2/src/

MAINTAINER=	augustss@cs.chalmers.se

USE_IMAKE=	yes
USE_MOTIF=	yes

post-patch:
	for file in ${WRKSRC}/XMmix.ad ${WRKSRC}/resource.h; do \
		${CP} $$file $$file.orig; \
		chmod +w $$file; \
		${SED} "s^/usr/lib/X11/xmmix.hlp^${PREFIX}/lib/X11/xmmix.hlp^" $$file.orig > $$file; \
	done

.include "../../mk/bsd.pkg.mk"
