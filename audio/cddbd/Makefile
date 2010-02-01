# $NetBSD: Makefile,v 1.14 2010/02/01 01:38:42 joerg Exp $
#

DISTNAME=	cddbd-1.3.1
PKGNAME=	cddbd-1.3.1p1
PKGREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/cddbd-1.3.1/}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cddbd-1.3.1.patch1.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedb.org/en/download__server_software.4.html
COMMENT=	Internet CD Database Server

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC};							\
	${SETENV} BASEDIR=${PREFIX:Q}/share ${SH} config.sh

do-install:
	cd ${WRKSRC};							\
	${SETENV} INSTALL=${INSTALL:Q} DESTDIR=${DESTDIR} 		\
	  BINDIR=${DESTDIR}${PREFIX}/bin	\
	  BINPERM=${BINMODE:Q} BINOWNER=${BINOWN:Q}			\
	  BINGROUP=${BINGRP:Q} ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
