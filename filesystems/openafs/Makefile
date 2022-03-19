# $NetBSD: Makefile,v 1.20 2022/03/19 16:19:02 jakllsch Exp $

DISTNAME=	openafs-1.8.8.1-src
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	filesystems net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/1.8.8.1/
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

# No idea if this is still needed;
# might also depend on bmake vs. gmake whether this works,
# seems more likely to work with gmake, but we're using bmake.
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		lex autoconf automake
RCD_SCRIPTS+=		bosserver

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

# Avoid _res in multithreaded on NetBSD
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_res_retransretry=no
.endif

USE_GNU_CONFIGURE_HOST=	no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PLIST_SRC+=		${.CURDIR}/PLIST
OWN_DIRS+=		${PKG_SYSCONFDIR}/openafs
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openafs/server ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/openafs ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 770
OWN_DIRS+=		${VARBASE}/openafs/logs
OWN_DIRS_PERMS+=	${VARBASE}/openafs/db ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}

BUILD_DEFS+=	VARBASE

# attempt to future-proof configuration
pre-patch:
	cd ${WRKSRC}/src/config && for i in 80 90; do \
		${SED} -e 's|nbsd70|nbsd'$$i'|g' param.i386_nbsd70.h > param.i386_nbsd$$i.h; \
		${SED} -e 's|nbsd70|nbsd'$$i'|g' param.amd64_nbsd70.h > param.amd64_nbsd$$i.h; \
		${CP} param.nbsd70.h param.nbsd$$i.h; \
	done

post-patch:
	${CP} ${WRKSRC}/src/config/param.armv6_nbsd80.h ${WRKSRC}/src/config/param.armv7_nbsd80.h

pre-configure:
	cd ${WRKSRC} && ./regen.sh -q

MAKE_ENV+=	LD_RUN_PATH=${PREFIX}/lib

# Can't do this yet.  Somehow doesn't work with pkgsrc heimdal,
# but does with NetBSD base heimdal.
#.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
