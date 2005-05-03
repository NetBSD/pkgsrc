# $NetBSD: Makefile,v 1.1.1.1 2005/05/03 19:30:40 agc Exp $

DISTNAME=	openafs-1.3.81-src
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/1.3.81/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-largefile-fileserver --enable-fast-restart
CONFIGURE_ARGS+= --enable-bitmap-later --disable-kernel-module
CONFIGURE_ARGS+= --enable-debug --enable-bos-new-config
CONFIGURE_ARGS+= --enable-namei-fileserver --prefix=${PREFIX}/openafs

USE_GNU_CONFIGURE_HOST= no

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
