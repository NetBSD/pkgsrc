# $NetBSD: Makefile,v 1.24 2005/08/23 11:48:47 rillig Exp $

DISTNAME=	distcc-2.18.3
CATEGORIES=	devel
MASTER_SITES=	http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://distcc.samba.org/
COMMENT=	Tool for distributed C/C++ compiling

USE_PKGINSTALL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-rfc2553
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	distcc
RCD_SCRIPTS=		distccd

DISTCC_USER?=		distcc
DISTCC_GROUP?=		distcc
PKG_GROUPS=		${DISTCC_GROUP}
PKG_USERS=      	${DISTCC_USER}:${DISTCC_GROUP}::Distccd\ user

DISTCC_PIDDIR?=		${VARBASE}/run/distccd
OWN_DIRS_PERMS=		${DISTCC_PIDDIR} ${DISTCC_USER} ${DISTCC_GROUP} 0750

FILES_SUBST+=		DISTCC_PIDDIR=${DISTCC_PIDDIR}
FILES_SUBST+=		DISTCC_USER=${DISTCC_USER}
FILES_SUBST+=		DISTCC_GROUP=${DISTCC_GROUP}

SUBST_CLASSES=		doc
SUBST_STAGE.doc=	post-patch
SUBST_FILES.doc=	src/distcc.c src/hosts.c
SUBST_SED.doc=		-e "s|%s/distcc/hosts|%s/hosts|g"
SUBST_MESSAGE.doc=	"Fixing paths."

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
