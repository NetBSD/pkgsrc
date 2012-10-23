# $NetBSD: Makefile,v 1.11 2012/10/23 19:51:28 asau Exp $
#

DISTNAME=		user-20101223
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Darwin-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/useradd.sh ${DESTDIR}${PREFIX}/sbin/useradd
	${INSTALL_SCRIPT} ${FILESDIR}/userdel.sh ${DESTDIR}${PREFIX}/sbin/userdel
	${INSTALL_SCRIPT} ${FILESDIR}/groupadd.sh ${DESTDIR}${PREFIX}/sbin/groupadd
	${INSTALL_SCRIPT} ${FILESDIR}/groupdel.sh ${DESTDIR}${PREFIX}/sbin/groupdel

.include "../../mk/bsd.pkg.mk"
