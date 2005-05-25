# $NetBSD: Makefile,v 1.2 2005/05/25 22:09:39 gendalia Exp $

DISTNAME=	openafs-1.3.82-src
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/1.3.82/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-largefile-fileserver --enable-fast-restart
CONFIGURE_ARGS+= --enable-bitmap-later --disable-kernel-module
CONFIGURE_ARGS+= --enable-debug --enable-bos-new-config
CONFIGURE_ARGS+= --enable-namei-fileserver --prefix=${PREFIX}/openafs

USE_GNU_CONFIGURE_HOST= no

WRKSRC=		${WRKDIR}/${PKGNAME}

PKG_SUPPORTED_OPTIONS = PAM
PKG_OPTIONS_VAR       = PKG_OPTIONS.openafs
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MPAM)
CONFIGURE_ARGS+=        --enable-pam
.include "../../mk/pam.buildlink3.mk"
PLIST_SRC+=		${.CURDIR}/PLIST.pam
.else
CONFIGURE_ARGS+=        --disable-pam
.endif

.include "../../mk/bsd.pkg.mk"
