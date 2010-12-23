# $NetBSD: Makefile,v 1.10 2010/12/23 12:44:46 obache Exp $
#

DISTNAME=		user-20101223
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

PKG_DESTDIR_SUPPORT=	user-destdir

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
