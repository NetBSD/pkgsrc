# $NetBSD: Makefile,v 1.32 2020/03/13 08:19:25 rillig Exp $
#

GITHUB_PROJECT=	checkperms
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	checkperms-1.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rillig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rillig/checkperms/
COMMENT=	Check and correct file permissions
LICENSE=	modified-bsd


AUTO_MKDIRS=		yes

USE_BSD_MAKEFILE=	yes

CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

.include "../../mk/compiler.mk"

MAKE_FLAGS+=		CWARNFLAGS.clang=-Wno-error=missing-noreturn

.include "../../mk/bsd.prefs.mk"

# Avoid self-referential and circular dependencies.
CHECK_PERMS_SKIP=	*
IGNORE_CCACHE=		yes
IGNORE_DISTCC=		yes

MAKE_ENV.Linux+=	NOGCCERROR=yes		# see PR 35930

# Avoid catpage regeneration
post-extract:
	${ECHO} ".PHONY: checkperms.cat1" >> ${WRKSRC}/Makefile
	${ECHO} "checkperms.cat1:" >> ${WRKSRC}/Makefile
	${ECHO} "" >> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
