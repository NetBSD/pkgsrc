# $NetBSD: Makefile,v 1.33 2013/01/04 06:00:48 apb Exp $

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
USE_BSD_MAKEFILE=	yes

VERSION=		0.7.1

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

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      kver/kver.sh kver/kver.8 lib/kver.3
SUBST_SED.paths+=       -e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=       -e 's,@SH@,${SH},g'
SUBST_STAGE.paths=      post-patch

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8 ${PKGMANDIR}/cat8
INSTALLATION_DIRS+=	lib ${PKGMANDIR}/man3 ${PKGMANDIR}/cat3
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
