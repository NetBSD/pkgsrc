# $NetBSD: Makefile,v 1.16 2010/01/27 19:17:41 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-205
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Motherboard monitoring utility

BUILD_TARGET=	mbmon

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mbmon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
