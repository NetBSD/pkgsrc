# $NetBSD: Makefile,v 1.27 2003/12/03 06:44:45 martti Exp $

DISTNAME=	etcupdate-20031112
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Documentation/current/
COMMENT=	Script to update the configuration and startup files in /etc

ONLY_FOR_PLATFORM=	NetBSD-*-*

EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/etcupdate ${PREFIX}/bin/etcupdate
	${INSTALL_MAN} ${FILESDIR}/etcupdate.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
