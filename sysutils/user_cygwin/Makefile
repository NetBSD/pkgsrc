# $NetBSD: Makefile,v 1.3 2013/03/12 05:41:39 obache Exp $
#

DISTNAME=		user-20130312
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		obache@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Cygwin-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	sbin

do-install:
.for f in useradd userdel groupadd groupdel
	${INSTALL_SCRIPT} ${FILESDIR}/${f}.sh ${DESTDIR}${PREFIX}/sbin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
