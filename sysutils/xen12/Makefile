# $NetBSD: Makefile,v 1.3 2004/05/22 17:21:52 cl Exp $
#

DISTNAME=		xeno-1.2-src-040418
PKGNAME=		xen12-040418
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/arch/xen/misc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cl@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Ports/xen/
COMMENT=		Xen Virtual Machine Monitor

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/xeno-1.2/xen
ALL_TARGET=		default

USE_PKGINSTALL=		yes

USE_GNU_TOOLS+=		make

post-extract:
	@${CP} ${FILESDIR}/gcc333-stdarg.h ${WRKSRC}/include/stdarg.h

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/xen.gz ${PREFIX}/mdec/xen-1.2.gz

.include "../../mk/bsd.pkg.mk"
