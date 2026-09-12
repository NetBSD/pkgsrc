# $NetBSD: Makefile,v 1.29 2026/09/12 15:45:25 jakllsch Exp $

DISTNAME=	openafs-1.8.16.1-src
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	filesystems net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	https://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration
LICENSE=	ipl-1.0 AND mit AND modified-bsd # AND sun-rpc?

PREV_PKGPATH=	net/openafs

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	lwp-[0-9]*
CONFLICTS+=	rx-[0-9]*

# upstream build system needs to be adapted for each version of an operating system
NOT_FOR_PLATFORM+=	NetBSD-1[3-9].*-*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		lex autoconf automake
USE_TOOLS+=		gmake # already needed for other build dependencies
RCD_SCRIPTS+=		bosserver

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--without-swig	# avoids missing "EXTERN.h" include on Linux

# Avoid _res in multithreaded on NetBSD
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_res_retransretry=no
.endif

USE_GNU_CONFIGURE_HOST=	no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PLIST_SRC+=		${PLIST_SRC_DFLT}
OWN_DIRS+=		${PKG_SYSCONFDIR}/openafs
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openafs/server ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/openafs ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 770
OWN_DIRS+=		${VARBASE}/openafs/logs
OWN_DIRS_PERMS+=	${VARBASE}/openafs/db ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}

BUILD_DEFS+=	VARBASE

pre-configure:
	cd ${WRKSRC} && ./regen.sh -q

MAKE_ENV+=	LD_RUN_PATH=${PREFIX}/lib

# Can't do this yet.  Somehow doesn't work on NetBSD with pkgsrc
# krb5/heimdal, but does with NetBSD base heimdal.
#.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
