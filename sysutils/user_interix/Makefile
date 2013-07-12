# $NetBSD: Makefile,v 1.11 2013/07/12 10:41:58 jperkin Exp $
#

DISTNAME=		user-interix-20130712
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
