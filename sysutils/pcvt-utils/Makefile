# $NetBSD: Makefile,v 1.5 2004/01/20 12:26:15 agc Exp $
#

DISTNAME=	netbsd-pcvt-20000611
PKGNAME=	pcvt-utils-20000611
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://cvsweb.NetBSD.org/bsdweb.cgi/syssrc/sys/arch/i386/isa/pcvt/
COMMENT=	Useful leftovers from pcvt: playvt and two font editors

ONLY_FOR_PLATFORM= NetBSD-*-*

WRKSRC=		${WRKDIR}/pcvt/Util

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/demo/playvt \
		${WRKSRC}/fed/fed \
		${WRKSRC}/fontedit/fontedit \
		${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/playvt
	${INSTALL_DATA} \
		${WRKSRC}/demo/*.vt \
		${PREFIX}/share/playvt

.include "../../mk/bsd.pkg.mk"
