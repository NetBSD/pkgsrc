# $NetBSD: Makefile,v 1.24 2003/05/09 08:03:08 martti Exp $

DISTNAME=	etcupdate-20030509
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Documentation/current/
COMMENT=	Script to update the configuration and startup files in /etc

EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/etcupdate ${PREFIX}/bin/etcupdate
	${INSTALL_MAN} ${FILESDIR}/etcupdate.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
