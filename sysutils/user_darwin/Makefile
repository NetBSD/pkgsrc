# $NetBSD: Makefile,v 1.1.1.1 2004/04/01 02:58:32 danw Exp $
#

DISTNAME=		user-20040331
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		danw@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Darwin-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CHECKSUM=		yes
NO_BUILDLINK=		yes
NO_CONFIGURE=		yes
NO_TOOLS=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/useradd.sh ${PREFIX}/sbin/useradd
	${INSTALL_SCRIPT} ${FILESDIR}/userdel.sh ${PREFIX}/sbin/userdel
	${INSTALL_SCRIPT} ${FILESDIR}/groupadd.sh ${PREFIX}/sbin/groupadd
	${INSTALL_SCRIPT} ${FILESDIR}/groupdel.sh ${PREFIX}/sbin/groupdel

.include "../../mk/bsd.pkg.mk"
