# $NetBSD: Makefile,v 1.5 1999/11/20 20:03:36 hubertf Exp $
#

DISTNAME=	hpwake
PKGNAME=	wakeup-1.0
CATEGORIES=	sysutils net
MASTER_SITES=	http://server7.ik.mb.uni-siegen.de/wol/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.berens-partner.de/wann/computer/wol.html

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
