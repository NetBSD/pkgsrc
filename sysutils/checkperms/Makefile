# $NetBSD: Makefile,v 1.22 2009/12/14 21:25:14 gdt Exp $
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

# Avoid self-referential and circular dependencies.
CHECK_PERMS=		no
IGNORE_CCACHE=		yes
IGNORE_DISTCC=		yes

.if ${OPSYS} == "Linux"
MAKE_ENV+=	NOGCCERROR=yes		# see PR 35930
.endif

.include "../../mk/bsd.pkg.mk"
