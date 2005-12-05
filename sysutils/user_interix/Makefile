# $NetBSD: Makefile,v 1.5 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=		user-20040426
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tv@duh.org
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
