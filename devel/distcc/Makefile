# $NetBSD: Makefile,v 1.18 2004/11/16 09:24:50 xtraeme Exp $

DISTNAME=		distcc-2.18.2
CATEGORIES=		devel
MASTER_SITES=		http://distcc.samba.org/ftp/distcc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://distcc.samba.org/
COMMENT=		Tool for distributed C/C++ compiling

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-rfc2553
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	distcc
RCD_SCRIPTS=		distccd

DISTCC_PIDDIR?=		${VARBASE}/run/distccd
OWN_DIRS_PERMS=		${DISTCC_PIDDIR} nobody nobody 0750

FILES_SUBST+=		DISTCC_PIDDIR=${DISTCC_PIDDIR}

SUBST_CLASSES=		doc
SUBST_STAGE.doc=	post-patch
SUBST_FILES.doc=	src/distcc.c src/hosts.c
SUBST_SED.doc=		-e "s|%s/distcc/hosts|%s/hosts|g"
SUBST_MESSAGE.doc=	"Fixing paths."

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
