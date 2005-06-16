# $NetBSD: Makefile,v 1.8 2005/06/16 18:25:36 gendalia Exp $

DISTNAME=	openafs-1.3.84-src
PKGREVISION=	1
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/1.3.84/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration

CONFLICTS+=	lwp-[0-9]*
CONFLICTS+=	rx-[0-9]*
CONFLICTS+=	arla-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-largefile-fileserver --enable-fast-restart
CONFIGURE_ARGS+= --enable-bitmap-later --disable-kernel-module
CONFIGURE_ARGS+= --enable-debug --enable-bos-new-config
CONFIGURE_ARGS+= --enable-namei-fileserver
CONFIGURE_ARGS+= --localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}

USE_GNU_CONFIGURE_HOST= no

WRKSRC=		${WRKDIR}/${PKGNAME}

PKG_SUPPORTED_OPTIONS = pam
PKG_OPTIONS_VAR       = PKG_OPTIONS.openafs
RCD_SCRIPTS+=	bosserver
.include "../../mk/bsd.options.mk"

USE_PKGINSTALL=		yes

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=        --enable-pam
.include "../../mk/pam.buildlink3.mk"
PLIST_SRC+=		${.CURDIR}/PLIST.pam
.else
CONFIGURE_ARGS+=        --disable-pam
.endif
PLIST_SRC+=		${.CURDIR}/PLIST
OWN_DIRS+=		${PKG_SYSCONFDIR}/openafs
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openafs/server ${ROOT_USER} ${ROOT_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/openafs ${ROOT_USER} ${ROOT_GROUP} 770
OWN_DIRS+=		${VARBASE}/openafs/logs
OWN_DIRS_PERMS+=	${VARBASE}/openafs/db ${ROOT_USER} ${ROOT_GROUP} 700

FILES_SUBST+= HOSTNAME_CMD=${HOSTNAME_CMD:Q}
.include "../../mk/bsd.pkg.mk"
