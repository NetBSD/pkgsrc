# $NetBSD: Makefile,v 1.5 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=		user-20040801
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		danw@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Darwin-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/useradd.sh ${PREFIX}/sbin/useradd
	${INSTALL_SCRIPT} ${FILESDIR}/userdel.sh ${PREFIX}/sbin/userdel
	${INSTALL_SCRIPT} ${FILESDIR}/groupadd.sh ${PREFIX}/sbin/groupadd
	${INSTALL_SCRIPT} ${FILESDIR}/groupdel.sh ${PREFIX}/sbin/groupdel

.include "../../mk/bsd.pkg.mk"
