# $NetBSD: Makefile,v 1.4 2003/07/17 21:37:26 grant Exp $

DISTNAME=       fontkit-nobdf
PKGNAME=        mglfonts-0.1
CATEGORIES=     fonts
MASTER_SITES=   http://www.at.sakura.ne.jp/~suz/arc/

MAINTAINER=     fk200329@fsinet.or.jp
HOMEPAGE=	http://www.NetBSD.org/Ports/hpcmips/mgl2.html
COMMENT=	MGL2 fonts and font tools

#HF#DEPENDS= 	mgl>=0.1.9a:../../graphics/mgl

#HF# .include "../../mk/bsd.prefs.mk"

post-extract:
	${MV} -f ${WRKDIR}/fontkit ${WRKDIR}/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
