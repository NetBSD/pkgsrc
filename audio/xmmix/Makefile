# New ports collection makefile for:	xmmix
# Version required:     1.2-pl2
# Date created:		97-10-24
# Whom:			augustss@cs.chalmers.se
#
# $NetBSD: Makefile,v 1.7 1998/03/19 10:42:01 frueauf Exp $
# FreeBSD ID: Makefile,v 1.5 1997/09/08 13:37:47 tg Exp
#

DISTNAME=       xmmix-1.2
CATEGORIES=	audio
MASTER_SITES=   http://mercury.hypersurf.com/~amb/download/xmmix-1.2/src/

MAINTAINER=	augustss@cs.chalmers.se

USE_IMAKE=	yes
REQUIRES_MOTIF=	yes

CAT1=		xmmix.0

post-patch:
	for file in ${WRKSRC}/XMmix.ad ${WRKSRC}/resource.h; do \
		${CP} $$file $$file.orig; \
		${SED} "s^/usr/lib/X11/xmmix.hlp^${PREFIX}/lib/X11/xmmix.hlp^" $$file.orig > $$file; \
	done

.include <bsd.port.mk>
