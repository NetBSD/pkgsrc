# $NetBSD: Makefile,v 1.16 2019/11/03 11:45:57 rillig Exp $
#

DISTNAME=	hpwake
PKGNAME=	wakeup-1.0
CATEGORIES=	net sysutils
MASTER_SITES=	http://server7.ik.mb.uni-siegen.de/wol/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.berens-partner.de/wann/computer/wol.html
COMMENT=	Wakeup On LAN client for remote power-up of machines

USE_TOOLS+=		gunzip
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin

LDFLAGS.SunOS+=	-lsocket

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
