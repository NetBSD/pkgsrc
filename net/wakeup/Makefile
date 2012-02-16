# $NetBSD: Makefile,v 1.14 2012/02/16 19:34:47 hans Exp $
#

DISTNAME=	hpwake
PKGNAME=	wakeup-1.0
CATEGORIES=	net sysutils
MASTER_SITES=	http://server7.ik.mb.uni-siegen.de/wol/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.berens-partner.de/wann/computer/wol.html
COMMENT=	Wakeup On LAN client for remote power-up of machines

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gunzip
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin

LDFLAGS.SunOS+=	-lsocket

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
