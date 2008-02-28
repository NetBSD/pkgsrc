# $NetBSD: Makefile,v 1.18 2008/02/28 11:58:49 rillig Exp $
#

DISTNAME=	checkperms-1.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schlechte-software.de/checkperms/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.schlechte-software.de/checkperms/
COMMENT=	Check and correct file permissions
#LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=			yes

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin man/cat1 man/man1
CHECK_PERMS=		no

.if ${OPSYS} == "Linux"
MAKE_ENV+=	NOGCCERROR=yes		# see PR 35930
.endif

.include "../../mk/bsd.pkg.mk"
