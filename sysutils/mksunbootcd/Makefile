# $NetBSD: Makefile,v 1.12 2025/09/21 21:22:40 wiz Exp $
#

DISTNAME=	mksunbootcd-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/mksunbootcd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/
COMMENT=	Combines filesystems for Sun computers to make bootable CD-ROM images

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
