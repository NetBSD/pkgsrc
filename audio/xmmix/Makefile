# $NetBSD: Makefile,v 1.30 2011/12/09 14:36:33 drochner Exp $

DISTNAME=	xmmix-1.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmmix/1.2.2/src/

MAINTAINER=	augustss@cs.chalmers.se
HOMEPAGE=	http://www.amb.org/xmmix/
COMMENT=	X interface to the audio mixer device

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

pre-configure:
	cd ${WRKSRC}; for file in XMmix.ad resource.h; do		\
		${SED} -e "s|/usr/lib/X11/|${PREFIX}/lib/X11/|g"	\
			$$file > $$file.fixed;				\
		${MV} -f $$file.fixed $$file;				\
	done

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
