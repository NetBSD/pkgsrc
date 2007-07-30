# $NetBSD: Makefile,v 1.11 2007/07/30 10:18:32 joerg Exp $
#

DISTNAME=	checkperms-1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schlechte-software.de/checkperms/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.schlechte-software.de/checkperms/
COMMENT=	Check and correct file permissions

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS=		no

.if ${OPSYS} == "Linux"
MAKE_ENV+=	NOGCCERROR=yes		# see PR 35930
.endif

.include "../../mk/bsd.pkg.mk"
