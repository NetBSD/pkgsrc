# $NetBSD: Makefile,v 1.11 2006/11/09 09:38:12 rillig Exp $
#

DISTNAME=	hpwake
PKGNAME=	wakeup-1.0
CATEGORIES=	net sysutils
MASTER_SITES=	http://server7.ik.mb.uni-siegen.de/wol/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.berens-partner.de/wann/computer/wol.html
COMMENT=	Wakeup On LAN client for remote power-up of machines

USE_TOOLS+=	gunzip
MAKE_ENV+=	${BSD_MAKE_ENV}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
