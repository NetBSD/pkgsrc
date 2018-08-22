# $NetBSD: Makefile,v 1.28 2018/08/22 09:46:31 wiz Exp $

DISTNAME=		cdbkup-1.0
PKGREVISION=		13
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdbkup/}

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/cdbkup/
COMMENT=		CD-R(W) backup/restore system

DEPENDS+=		{cdrtools,cdrtools-ossdvd}>=1.10:../../sysutils/cdrtools

GNU_CONFIGURE=		YES
USE_TOOLS+=		cat bzip2:run date gtar:run gzip:run perl:run
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}
CONFIGURE_ENV+=		DATE=${TOOLS_DATE:Q}
CONFIGURE_ENV+=		GNUTAR=${TOOLS_GTAR:Q}
CONFIGURE_ENV+=		ac_cv_path_BZIP=${TOOLS_PATH.bzip2:Q}
CONFIGURE_ENV+=		ac_cv_path_GZIP=${TOOLS_PATH.gzip:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CDBKUP_SNARDIR?=	/var/${PKGBASE}
CDBKUP_DUMPGRP?=	sys
.else
CDBKUP_SNARDIR?=	/var/db/${PKGBASE}
CDBKUP_DUMPGRP?=	operator
.endif

CONFIGURE_ENV.NetBSD+=	MOUNT=/sbin/mount UMOUNT=/sbin/umount

CONFIGURE_ARGS+=	--with-snardir=${CDBKUP_SNARDIR:Q} \
			--with-dumpgrp=${CDBKUP_DUMPGRP:Q}
PLIST_SUBST+=		CDBKUP_SNARDIR=${CDBKUP_SNARDIR:Q} \
			CDBKUP_DUMPGRP=${CDBKUP_DUMPGRP:Q} \
			INSTALL=${INSTALL:Q} RMDIR=${RMDIR:Q} TRUE=${TRUE:Q}

.include "../../mk/bsd.pkg.mk"
