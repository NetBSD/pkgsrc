# $NetBSD: Makefile,v 1.28 2013/09/08 16:33:59 joerg Exp $
#

DISTNAME=	checkperms-1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.roland-illig.de/checkperms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roland-illig.de/checkperms/
COMMENT=	Check and correct file permissions
LICENSE=	modified-bsd

AUTO_MKDIRS=		yes

USE_BSD_MAKEFILE=	yes

.include "../../mk/compiler.mk"

MAKE_FLAGS+=		CWARNFLAGS.clang=-Wno-error=missing-noreturn

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
	${ECHO} ".PHONY: checkperms.cat1" >> ${WRKSRC}/Makefile
	${ECHO} "checkperms.cat1:" >> ${WRKSRC}/Makefile
	${ECHO} "" >> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
