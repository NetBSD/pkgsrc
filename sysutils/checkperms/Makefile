# $NetBSD: Makefile,v 1.21 2009/12/05 10:23:34 rillig Exp $
#

DISTNAME=	checkperms-1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.roland-illig.de/checkperms/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.roland-illig.de/checkperms/
COMMENT=	Check and correct file permissions
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=		yes

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

# Avoid the "hen and egg problem"
CHECK_PERMS=		no

.if ${OPSYS} == "Linux"
MAKE_ENV+=	NOGCCERROR=yes		# see PR 35930
.endif

.include "../../mk/bsd.pkg.mk"
