# $NetBSD: Makefile,v 1.8 2009/02/13 22:30:22 abs Exp $
#

DISTNAME=	misc-src-riscpc
PKGNAME=	vidc-tools-1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/arch/arm32/misc/

MAINTAINER=	abs@NetBSD.org
COMMENT=	Tools for the VIDC console used by NetBSD/arm32 on RiscPC

WRKSRC=		${WRKDIR}/misc-src

ONLY_FOR_PLATFORM= NetBSD-*-arm NetBSD-*-arm32

INSTALLATION_DIRS = bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/html1 ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT = user-destdir

.include "../../mk/bsd.pkg.mk"
