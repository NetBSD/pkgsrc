# $NetBSD: Makefile,v 1.4 2003/07/20 15:37:46 seb Exp $

DISTNAME=		libkver-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=	seb@NetBSD.org
#HOMEPAGE=
COMMENT=	shared library and sysctl(1) replacement to override system version

USE_BUILDLINK2=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_PKG_REGISTER=	# defined
NO_PACKAGE=		Deinstallation is not permitted

VERSION=		0.1

ONLY_FOR_PLATFORM=	NetBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if defined(KVER_OSRELEASE)
MAKE_ENV+=	KVER_OSRELEASE=${KVER_OSRELEASE}
.endif

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
