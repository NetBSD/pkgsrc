# $NetBSD: Makefile,v 1.10 2012/10/23 19:51:28 asau Exp $
#

DISTNAME=		user-20040426
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		interix-pkg-people@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	sbin

do-install:
.for f in useradd userdel groupadd groupdel
	${INSTALL_SCRIPT} ${FILESDIR}/${f}.sh ${DESTDIR}${PREFIX}/sbin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
