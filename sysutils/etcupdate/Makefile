# $NetBSD: Makefile,v 1.10 2001/12/15 09:05:07 martti Exp $

DISTNAME=	etcupdate-20011215
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Documentation/current/
COMMENT=	Script to update the configuration and startup files in /etc

EXTRACT_ONLY=	# defined
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/etcupdate ${PREFIX}/bin/etcupdate
	${INSTALL_MAN} ${FILESDIR}/etcupdate.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
