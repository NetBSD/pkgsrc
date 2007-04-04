# $NetBSD: Makefile,v 1.7 2007/04/04 14:37:53 tv Exp $
#

DISTNAME=		user-20040426
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		interix-pkg-people@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	sbin

do-install:
.for f in useradd userdel groupadd groupdel
	${INSTALL_SCRIPT} ${FILESDIR}/${f}.sh ${PREFIX}/sbin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
