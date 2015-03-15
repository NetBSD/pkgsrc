# $NetBSD: Makefile,v 1.7 2015/03/15 20:13:24 hiramatsu Exp $
#

DISTNAME=		user-cygwin-20130712
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Limited NetBSD-compatible useradd/groupadd commands

ONLY_FOR_PLATFORM=	Cygwin-*-*

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	sbin

do-install:
.for f in useradd userdel groupadd groupdel
	${INSTALL_SCRIPT} ${FILESDIR}/${f}.sh ${DESTDIR}${PREFIX}/sbin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
