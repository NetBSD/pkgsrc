# $NetBSD: Makefile,v 1.17 2001/09/09 03:08:49 jlam Exp $
# FreeBSD ID: Makefile,v 1.5 1997/09/08 13:37:47 tg Exp
#

DISTNAME=       xmmix-1.2
CATEGORIES=	audio
MASTER_SITES=   http://mercury.hypersurf.com/~amb/download/xmmix-1.2/src/

MAINTAINER=	augustss@cs.chalmers.se
HOMEPAGE=	http://sunsite.unc.edu/~cddb/xmmix/index.html
COMMENT=	X interface to the audio mixer device

USE_IMAKE=	yes

post-patch:
	for file in ${WRKSRC}/XMmix.ad ${WRKSRC}/resource.h; do		\
		${MV} -f $$file $$file.orig;				\
		${SED} -e "s|/usr/lib/X11/xmmix.hlp|${PREFIX}/lib/X11/xmmix.hlp|g" \
			$$file.orig > $$file;				\
	done

.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
