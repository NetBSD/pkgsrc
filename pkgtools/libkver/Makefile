# $NetBSD: Makefile,v 1.6 2003/09/30 19:13:30 seb Exp $

DISTNAME=		libkver-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=	seb@NetBSD.org
#HOMEPAGE=
COMMENT=	Shared library and sysctl(1) replacement to override system version

USE_BUILDLINK2=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_PKG_REGISTER=	# defined
NO_PACKAGE=		Deinstallation is not permitted

VERSION=		0.2

ONLY_FOR_PLATFORM=	NetBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if defined(KVER_OSRELEASE)
MAKE_ENV+=	KVER_OSRELEASE=${KVER_OSRELEASE}
.endif

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
