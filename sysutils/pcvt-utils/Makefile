# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:29 jmmv Exp $
#

DISTNAME=	netbsd-pcvt-20000611
PKGNAME=	pcvt-utils-20000611
WRKSRC=		${WRKDIR}/pcvt/Util
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://cvsweb.netbsd.org/bsdweb.cgi/syssrc/sys/arch/i386/isa/pcvt/
COMMENT=	Useful leftovers from pcvt: playvt and two font editors

ONLY_FOR_PLATFORM= NetBSD-*-*

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
