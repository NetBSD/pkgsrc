# $NetBSD: Makefile,v 1.8 2003/12/13 17:45:59 seb Exp $

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

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib
.if empty(LDD_SYSCTL:M*libc*)
	${INSTALL_DATA_DIR} ${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"
