# $NetBSD: Makefile,v 1.26 2013/02/21 07:58:21 wiz Exp $
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

.if !empty(CC_VERSION:Mclang*)
MAKE_FLAGS+=		ACTIVE_CC=clang
.endif

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
