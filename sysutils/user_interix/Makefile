# $NetBSD: Makefile,v 1.9 2010/01/27 20:30:47 joerg Exp $
#

DISTNAME=		user-20040426
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		interix-pkg-people@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

PKG_DESTDIR_SUPPORT=	user-destdir

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
