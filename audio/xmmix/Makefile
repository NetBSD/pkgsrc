# $NetBSD: Makefile,v 1.19 2003/02/25 02:22:29 jschauma Exp $
# FreeBSD ID: Makefile,v 1.5 1997/09/08 13:37:47 tg Exp
#

DISTNAME=       xmmix-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=   http://mercury.hypersurf.com/~amb/download/xmmix-1.2/src/

MAINTAINER=	augustss@cs.chalmers.se
HOMEPAGE=	http://sunsite.unc.edu/~cddb/xmmix/index.html
COMMENT=	X interface to the audio mixer device

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

pre-configure:
	cd ${WRKSRC}; for file in XMmix.ad resource.h; do		\
		${SED} -e "s|/usr/lib/X11/|${PREFIX}/lib/X11/|g"	\
			$$file > $$file.fixed;				\
		${MV} -f $$file.fixed $$file;				\
	done

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
