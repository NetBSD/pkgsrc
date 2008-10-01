# $NetBSD: Makefile,v 1.29 2008/10/01 20:16:50 tron Exp $

DISTNAME=		libkver-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=	seb@NetBSD.org
#HOMEPAGE=
COMMENT=	Shared library and sysctl(1) replacement to override system version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS=		no

NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
USE_BSD_MAKEFILE=	yes

VERSION=		0.6

ONLY_FOR_PLATFORM=	NetBSD-*-*

BUILDLINK_PASSTHRU_DIRS=	${BSDSRCDIR}/sys


PLIST_VARS=	sysctl
LDD_SYSCTL!=	ldd /sbin/sysctl 2>&1 || ${TRUE}
MAKE_ENV+=	LDD_SYSCTL=${LDD_SYSCTL:Q} # save another ldd run
.if empty(LDD_SYSCTL:M*libc*)
PLIST.sysctl=		yes
FILES_SUBST+=		HAS_SYSCTL=true
.else
FILES_SUBST+=		HAS_SYSCTL=false
.endif

INSTALLATION_DIRS+=	lib man/man3 man/cat3
.if empty(LDD_SYSCTL:M*libc*)
INSTALLATION_DIRS+=	sbin
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

LIBKVER_STANDALONE_PREFIX?=	/libkver
standalone-install:
	${MAKE} ${MAKEFLAGS} PKG_DBDIR=${LIBKVER_STANDALONE_PREFIX:Q}/pkg \
	  PREFIX=${LIBKVER_STANDALONE_PREFIX:Q} install

.include "../../mk/bsd.pkg.mk"
