# $NetBSD: Makefile,v 1.29 2004/01/20 12:26:15 agc Exp $

DISTNAME=	etcupdate-20031112
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Documentation/current/
COMMENT=	Script to update the configuration and startup files in /etc

ONLY_FOR_PLATFORM=	NetBSD-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_BUILDLINK=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

INSTALLATION_DIRS=	bin man/man8

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/etcupdate ${PREFIX}/bin/etcupdate
	${INSTALL_MAN} ${FILESDIR}/etcupdate.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
