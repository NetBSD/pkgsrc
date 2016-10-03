# $NetBSD: Makefile,v 1.4 2016/10/03 08:30:13 wiz Exp $

DISTNAME=	openafs-1.7.11-src
PKGNAME=	${DISTNAME:C/-src//}
PKGREVISION=	1
CATEGORIES=	filesystems net sysutils
MASTER_SITES=	http://www.openafs.org/dl/openafs/1.7.11/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://www.openafs.org/
COMMENT=	File system for sharing, scalability and transparent data migration
LICENSE=	ipl-1.0 AND mit AND modified-bsd # AND sun-rpc?

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	rx-[0-9]*

MAKE_JOBS_SAFE=no

GNU_CONFIGURE=		yes
USE_TOOLS+=		lex
RCD_SCRIPTS+=		bosserver

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-roken=internal

USE_GNU_CONFIGURE_HOST= no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PLIST_SRC+=		${.CURDIR}/PLIST
OWN_DIRS+=		${PKG_SYSCONFDIR}/openafs
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/openafs/server ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/openafs ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 770
OWN_DIRS+=		${VARBASE}/openafs/logs
OWN_DIRS_PERMS+=	${VARBASE}/openafs/db ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}

BUILD_DEFS+= VARBASE

#
# Rename liblwp.a to libafslwp.a to avoid conflict with the lwp package.
#
pre-configure:
	find ${WRKSRC} -name Makefile.in | while read f; do \
		${SED}	-e 's|liblwp.a|libafslwp.a|g' \
			-e 's|-llwp|-lafslwp|g' < $$f > $$f.tmp && \
		${MV} $$f.tmp $$f; done

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
