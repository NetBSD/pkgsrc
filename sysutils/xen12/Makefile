# $NetBSD: Makefile,v 1.12 2006/07/27 18:48:04 jlam Exp $
#

DISTNAME=		xeno-1.2-src-040418
PKGNAME=		xen12-040418
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/arch/xen/misc/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		xen12-addtl-ide-dma-040522.tar.gz

MAINTAINER=		cl@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Ports/xen/
COMMENT=		Xen Virtual Machine Monitor

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/xeno-1.2/xen
BUILD_TARGET=		default


USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		XEN12_USE_COM2

.if defined(XEN12_USE_COM2) && !empty(XEN12_USE_COM2:M[Yy][Ee][Ss])
PATCHFILES+=		xen12-com2-support-040522.diff
SITES.xen12-com2-support-040522.diff=ftp://ftp.NetBSD.org/pub/NetBSD/arch/xen/misc/
.endif

post-extract:
	@${CP} ${FILESDIR}/stdarg.h ${WRKSRC}/include/stdarg.h
	@${CP} ${WRKDIR}/xen12-addtl-ide-dma-040522/drivers/ide/* ${WRKSRC}/drivers/ide/

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/xen.gz ${PREFIX}/mdec/xen-1.2.gz

.include "../../mk/bsd.pkg.mk"
