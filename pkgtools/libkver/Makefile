# $NetBSD: Makefile,v 1.1.1.1 2003/07/11 14:50:37 seb Exp $

DISTNAME=		libkver-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=	seb@netbsd.org
#HOMEPAGE=
COMMENT=	shared librarie and sysctl(1) replacement to override system version

USE_BUILDLINK2=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_PKG_REGISTER=	# defined
NO_PACKAGE=		Deinstallation is not permitted

VERSION=		0.1

ONLY_FOR_PLATFORM=	NetBSD-*-*

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
