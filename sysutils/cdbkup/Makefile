# $NetBSD: Makefile,v 1.17 2011/12/29 16:38:37 joerg Exp $

DISTNAME=		cdbkup-1.0
PKGREVISION=		6
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdbkup/}

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/cdbkup/
COMMENT=		CD-R(W) backup/restore system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		{cdrtools,cdrtools-ossdvd}>=1.10:../../sysutils/cdrtools

GNU_CONFIGURE=		YES
USE_TOOLS+=		cat date gtar perl:run
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}
CONFIGURE_ENV+=		DATE=${TOOLS_DATE:Q}
CONFIGURE_ENV+=		GNUTAR=${TOOLS_GTAR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CDBKUP_SNARDIR?=	/var/${PKGBASE}
CDBKUP_DUMPGRP?=	sys
.else
CDBKUP_SNARDIR?=	/var/db/${PKGBASE}
CDBKUP_DUMPGRP?=	operator
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		MOUNT=/sbin/mount UMOUNT=/sbin/umount
.endif

CONFIGURE_ARGS+=	--with-snardir=${CDBKUP_SNARDIR:Q} \
			--with-dumpgrp=${CDBKUP_DUMPGRP:Q}
PLIST_SUBST+=		CDBKUP_SNARDIR=${CDBKUP_SNARDIR:Q} \
			CDBKUP_DUMPGRP=${CDBKUP_DUMPGRP:Q} \
			INSTALL=${INSTALL:Q} RMDIR=${RMDIR:Q} TRUE=${TRUE:Q}

.include "../../mk/bsd.pkg.mk"
