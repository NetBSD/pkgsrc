# $NetBSD: Makefile,v 1.7 2001/02/17 18:19:54 wiz Exp $
#

DISTNAME=	hpwake
PKGNAME=	wakeup-1.0
CATEGORIES=	net sysutils
MASTER_SITES=	http://server7.ik.mb.uni-siegen.de/wol/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.berens-partner.de/wann/computer/wol.html
COMMENT=	Wakeup On LAN client for remote power-up of machines

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
