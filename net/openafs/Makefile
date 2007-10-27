# $NetBSD: Makefile,v 1.24 2007/10/27 09:11:10 gendalia Exp $

DISTNAME=	openafs-1.4.5-src
PKGNAME=	${DISTNAME:C/-src//}
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/1.4.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	lwp-[0-9]*
CONFLICTS+=	rx-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		lex
RCD_SCRIPTS+=		bosserver

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

USE_GNU_CONFIGURE_HOST= no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PLIST_SRC+=		${.CURDIR}/PLIST
OWN_DIRS+=		${PKG_SYSCONFDIR}/openafs
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openafs/server ${ROOT_USER} ${ROOT_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/openafs ${ROOT_USER} ${ROOT_GROUP} 770
OWN_DIRS+=		${VARBASE}/openafs/logs
OWN_DIRS_PERMS+=	${VARBASE}/openafs/db ${ROOT_USER} ${ROOT_GROUP} 700

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}

# attempt to future-proof configuration
pre-build:
	cd ${WRKSRC}/src/config && for i in 40 50 60 70 80 90; do	\
		${SED} -e 's|nbsd20|nbsd'$$i'|g' param.i386_nbsd20.h > param.i386_nbsd$$i.h; \
		${CP} param.nbsd30.h param.nbsd$$i.h; 			\
	done

.include "../../mk/bsd.pkg.mk"
