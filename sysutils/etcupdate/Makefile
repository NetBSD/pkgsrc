# $NetBSD: Makefile,v 1.20 2003/03/28 21:14:35 wiz Exp $

DISTNAME=	etcupdate-20030204
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Documentation/current/
COMMENT=	Script to update the configuration and startup files in /etc

EXTRACT_ONLY=	# defined
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/etcupdate ${PREFIX}/bin/etcupdate
	${INSTALL_MAN} ${FILESDIR}/etcupdate.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
