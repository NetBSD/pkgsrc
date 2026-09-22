# $NetBSD: Makefile,v 1.34 2026/09/22 12:08:50 wiz Exp $

DISTNAME=		cdbkup-1.0
PKGREVISION=		18
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdbkup/}

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/cdbkup/
COMMENT=		CD-R(W) backup/restore system
LICENSE=		gnu-gpl-v2

DEPENDS+=		{cdrtools,cdrtools-ossdvd}>=1.10:../../sysutils/cdrtools

GNU_CONFIGURE=		YES
USE_TOOLS+=		cat bzip2:run date gtar:run gzip:run perl:run
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}
CONFIGURE_ENV+=		DATE=${TOOLS_DATE:Q}
CONFIGURE_ENV+=		GNUTAR=${TOOLS_GTAR:Q}
CONFIGURE_ENV+=		ac_cv_path_BZIP=${TOOLS_PATH.bzip2:Q}
CONFIGURE_ENV+=		ac_cv_path_GZIP=${TOOLS_PATH.gzip:Q}
CONFIGURE_ENV.NetBSD+=	MOUNT=/sbin/mount UMOUNT=/sbin/umount

CONFIGURE_ARGS+=	--with-snardir=${CDBKUP_SNARDIR:Q} \
			--with-dumpgrp=${CDBKUP_DUMPGRP:Q}

# Actually a bash script, would need REPLACE_BASH for running
CHECK_PORTABILITY_SKIP+=	test/test-suite.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CDBKUP_SNARDIR?=	${PREFIX}/var/${PKGBASE}
CDBKUP_DUMPGRP?=	sys
.else
CDBKUP_SNARDIR?=	${PREFIX}/var/db/${PKGBASE}
CDBKUP_DUMPGRP?=	operator
.endif

OWN_DIRS_PERMS+=	${CDBKUP_SNARDIR} ${REAL_ROOT_USER} ${CDBKUP_DUMPGRP} 750

.include "../../mk/bsd.pkg.mk"
