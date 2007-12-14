# $NetBSD: Makefile,v 1.16 2007/12/14 07:20:51 bjs Exp $
#

DISTNAME=	checkperms-1.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schlechte-software.de/checkperms/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.schlechte-software.de/checkperms/
COMMENT=	Check and correct file permissions
#LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS_FROM_PLIST=	yes

# Don't use USE_BSD_MAKEFILE here to avoid the dependency on nroff.
MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin man/cat1 man/man1
CHECK_PERMS=		no

.if ${OPSYS} == "Linux"
MAKE_ENV+=	NOGCCERROR=yes		# see PR 35930
.endif

.include "../../mk/bsd.pkg.mk"
