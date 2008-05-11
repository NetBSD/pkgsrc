# $NetBSD: Makefile,v 1.40 2008/05/11 00:00:57 tonnerre Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME}pl1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind8/src/${BIND_VERSION}/
DISTFILES=	bind-src.tar.gz bind-doc.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isc.org/sw/bind/
COMMENT=	The Berkeley Internet Name Daemon, an implementation of DNS

USE_TOOLS+=	lex yacc

WRKSRC=		${WRKDIR}
BIND_VERSION=	8.4.7
DIST_SUBDIR=	bind/${BIND_VERSION}

PATCH_SITES=		${MASTER_SITES:S/8.4.7/8.4.7-P1/}
PATCHFILES=		8.4.7-p1.patch
PATCH_DIST_STRIP=	-p1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
	${LN} -s freebsd ${WRKSRC}/src/port/dragonfly

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bind8
	cd ${WRKSRC}/doc/html && ${PAX} -rw * ${PREFIX}/share/doc/html/bind8
	${CHMOD} ${DOCMODE} ${PREFIX}/share/doc/html/bind8/*.html

.include "../../mk/bsd.pkg.mk"
