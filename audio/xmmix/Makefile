# $NetBSD: Makefile,v 1.10 1998/06/09 13:36:49 agc Exp $
# FreeBSD ID: Makefile,v 1.5 1997/09/08 13:37:47 tg Exp
#

DISTNAME=       xmmix-1.2
CATEGORIES=	audio
MASTER_SITES=   http://mercury.hypersurf.com/~amb/download/xmmix-1.2/src/

MAINTAINER=	augustss@cs.chalmers.se

USE_IMAKE=	yes
USE_MOTIF=	yes

CAT1=		xmmix.0

post-patch:
	for file in ${WRKSRC}/XMmix.ad ${WRKSRC}/resource.h; do \
		${CP} $$file $$file.orig; \
		chmod +w $$file; \
		${SED} "s^/usr/lib/X11/xmmix.hlp^${PREFIX}/lib/X11/xmmix.hlp^" $$file.orig > $$file; \
	done

.include "../../mk/bsd.pkg.mk"
