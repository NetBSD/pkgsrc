# $NetBSD: Makefile,v 1.33 2005/12/05 20:50:44 rillig Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/${BIND_VERSION}/
DISTFILES=	bind-src.tar.gz bind-doc.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/
COMMENT=	The Berkeley Internet Name Daemon, an implementation of DNS

WRKSRC=		${WRKDIR}
BIND_VERSION=	8.4.6
DIST_SUBDIR=	bind/${BIND_VERSION}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=	yes
RCD_SCRIPTS=	named

BUILD_DIRS=	src doc/man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	MANROFF=cat
MAKEFLAGS+=	INSTALL=${INSTALL:Q}
OWN_DIRS_PERMS=	${PKG_SYSCONFDIR}/ndc.d root other 700
.endif

MAKEFLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	INSTALL_LIB=-o\ ${LIBOWN}\ -g\ ${LIBGRP}

post-extract:
	cd ${WRKSRC}/doc/man && ${RM} -f *.lst* *~ *.BAK *.CKP *.orig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bind8
	cd ${WRKSRC}/doc/html && ${PAX} -rw * ${PREFIX}/share/doc/html/bind8

.include "../../mk/bsd.pkg.mk"
