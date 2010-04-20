# $NetBSD: Makefile,v 1.23 2010/04/20 16:01:38 tnn Exp $
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

# Avoid catpage regeneration
post-extract:
	echo ".PHONY: checkperms.cat1" >> ${WRKSRC}/Makefile
	echo "checkperms.cat1:" >> ${WRKSRC}/Makefile
	echo "" >> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
