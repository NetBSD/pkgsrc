# $NetBSD: Makefile,v 1.9 2003/12/23 19:48:31 seb Exp $

DISTNAME=		libkver-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=	seb@NetBSD.org
#HOMEPAGE=
COMMENT=	Shared library and sysctl(1) replacement to override system version

USE_BUILDLINK2=		# defined
USE_PKGINSTALL=		YES

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined

VERSION=		0.4

ONLY_FOR_PLATFORM=	NetBSD-*-*

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
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
