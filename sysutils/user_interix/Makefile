# $NetBSD: Makefile,v 1.1.1.1 2004/04/27 01:45:22 tv Exp $
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
NO_BUILDLINK=		yes
NO_CONFIGURE=		yes
NO_TOOLS=		yes
NO_BUILD=		yes

do-install:
.for f in useradd userdel groupadd groupdel
	${INSTALL_SCRIPT} ${FILESDIR}/$f.sh ${PREFIX}/sbin/$f
.endfor

.include "../../mk/bsd.pkg.mk"
