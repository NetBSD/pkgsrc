# $NetBSD: Makefile,v 1.17 2012/09/11 23:59:28 asau Exp $
#

DISTNAME=	cddbd-1.3.1
PKGNAME=	cddbd-1.3.1p1
PKGREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/cddbd-1.3.1/}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cddbd-1.3.1.patch1.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedb.org/en/download__server_software.4.html
COMMENT=	Internet CD Database Server
LICENSE=	gnu-gpl-v2

MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin

LDFLAGS.SunOS+=	-lsocket -lnsl

do-configure:
	cd ${WRKSRC} &&							\
	${SETENV} BASEDIR=${PREFIX}/share ${SH} config.sh

do-install:
	cd ${WRKSRC} &&							\
	${SETENV} INSTALL=${INSTALL:Q} DESTDIR=${DESTDIR} 		\
	  BINDIR=${DESTDIR}${PREFIX}/bin				\
	  BINPERM=${BINMODE} BINOWNER=${BINOWN}				\
	  BINGROUP=${BINGRP} ${SH} install.sh

.include "../../mk/bsd.pkg.mk"
