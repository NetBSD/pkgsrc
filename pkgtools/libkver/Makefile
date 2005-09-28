# $NetBSD: Makefile,v 1.15 2005/09/28 20:52:25 rillig Exp $

DISTNAME=		libkver-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=	seb@NetBSD.org
#HOMEPAGE=
COMMENT=	Shared library and sysctl(1) replacement to override system version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=		YES

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		yes
NO_MTREE=		yes

VERSION=		0.6

ONLY_FOR_PLATFORM=	NetBSD-*-*

BUILDLINK_PASSTHRU_DIRS=	${BSDSRCDIR}/sys

.include "../../mk/bsd.prefs.mk"

LDD_SYSCTL!=    ldd /sbin/sysctl 2>&1
MAKE_ENV+=	LDD_SYSCTL=${LDD_SYSCTL:Q} # save another ldd run
.if empty(LDD_SYSCTL:M*libc*)
PLIST_SUBST+=		HAS_SYSCTL=
FILES_SUBST+=		HAS_SYSCTL=true
.else
PLIST_SUBST+=		HAS_SYSCTL="@comment "
FILES_SUBST+=		HAS_SYSCTL=false
.endif

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

INSTALLATION_DIRS+=	lib man/man3 man/cat3
.if empty(LDD_SYSCTL:M*libc*)
INSTALLATION_DIRS+=	sbin
.endif

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
