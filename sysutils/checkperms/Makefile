# $NetBSD: Makefile,v 1.30 2016/02/26 10:24:11 jperkin Exp $
#

DISTNAME=	checkperms-1.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.roland-illig.de/checkperms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roland-illig.de/checkperms/
COMMENT=	Check and correct file permissions
LICENSE=	modified-bsd

AUTO_MKDIRS=		yes

USE_BSD_MAKEFILE=	yes

CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

.include "../../mk/compiler.mk"

MAKE_FLAGS+=		CWARNFLAGS.clang=-Wno-error=missing-noreturn

.include "../../mk/bsd.prefs.mk"

# Avoid self-referential and circular dependencies.
CHECK_PERMS=		no
IGNORE_CCACHE=		yes
IGNORE_DISTCC=		yes

MAKE_ENV.Linux+=	NOGCCERROR=yes		# see PR 35930

# Avoid catpage regeneration
post-extract:
	${ECHO} ".PHONY: checkperms.cat1" >> ${WRKSRC}/Makefile
	${ECHO} "checkperms.cat1:" >> ${WRKSRC}/Makefile
	${ECHO} "" >> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
