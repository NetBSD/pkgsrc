# $NetBSD: Makefile,v 1.2 2002/12/22 22:24:56 jmmv Exp $

DISTNAME=		cdbkup-1.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdbkup/} \
			ftp://batraq.anything3d.com/pub/cdbkup/cdbkup-1/ \
			http://mishka.terabyte.com.ua/cdbkup/

MAINTAINER=		mishka@terabyte.com.ua
HOMEPAGE=		http://sourceforge.net/projects/cdbkup/
COMMENT=		CD-R(W) backup/restore system

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		cdrecord>=1.10:../../sysutils/cdrecord
.if ${OPSYS} == "NetBSD" && ${OS_VERSION:M1.6[K-Z]}
DEPENDS+=		gtar-base>=1.13.25:../../archivers/gtar-base
.endif

GNU_CONFIGURE=		YES
USE_PERL5=		YES

.if (${OPSYS} == SunOS)
CDBKUP_SNARDIR?=	/var/${PKGBASE}
CDBKUP_DUMPGRP?=	sys
.else
CDBKUP_SNARDIR?=	/var/db/${PKGBASE}
CDBKUP_DUMPGRP?=	operator
.endif

CONFIGURE_ARGS+=	--with-snardir=${CDBKUP_SNARDIR} \
			--with-dumpgrp=${CDBKUP_DUMPGRP}
PLIST_SUBST+=		CDBKUP_SNARDIR=${CDBKUP_SNARDIR} \
			CDBKUP_DUMPGRP=${CDBKUP_DUMPGRP} \
			INSTALL=${INSTALL} RMDIR=${RMDIR} TRUE=${TRUE}

.include "../../mk/bsd.pkg.mk"
