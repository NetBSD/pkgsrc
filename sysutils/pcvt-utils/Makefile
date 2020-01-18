# $NetBSD: Makefile,v 1.15 2020/01/18 23:35:20 rillig Exp $
#

DISTNAME=	netbsd-pcvt-20000611
PKGNAME=	pcvt-utils-20000611
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cvsweb.NetBSD.org/bsdweb.cgi/src/sys/arch/i386/isa/pcvt/
COMMENT=	Useful leftovers from pcvt: playvt and two font editors

ONLY_FOR_PLATFORM=	NetBSD-*-*
USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}/pcvt/Util

AUTO_MKDIRS=			yes

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/demo/playvt \
		${WRKSRC}/fed/fed \
		${WRKSRC}/fontedit/fontedit \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/demo/*.vt \
		${DESTDIR}${PREFIX}/share/playvt

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
