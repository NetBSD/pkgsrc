# $NetBSD: Makefile,v 1.11 2024/05/23 15:08:18 cheusov Exp $
#

DISTNAME=	nbase-9.3.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/nbase
COMMENT=	NetBSD userlevel portable to other UNIX-like systems
LICENSE=	modified-bsd

GITHUB_PROJECT=	nbase
TOOL_DEPENDS+=	mk-configure>=0.34.0:../../devel/mk-configure

USE_LANGUAGES=		c
USE_TOOLS+=		flex:run byacc

TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"
.include "../../devel/mk-configure/mk-c.mk"

.if "${OPSYS}" != "NetBSD" && "${OPSYS}" != "FreeBSD" && "${OPSYS}" != "OpenBSD" && "${OPSYS}" != "DragonFly"
.include "../../devel/libbsd/buildlink3.mk"
.endif

.if "${OPSYS}" != "NetBSD"
.include "../../devel/libmd/buildlink3.mk"
.endif

MAKE_FLAGS+=	PREFIX=${PREFIX}/nbase \
		MANDIR=${PREFIX}/nbase/${PKGMANDIR} \
		LINKSPREFIX=${PREFIX} \
		USE_NB_PREFIX=nb-

# -Wno-error=unused-result -Werror=strict-aliasing(libnbcompat,)
MAKE_FLAGS+=	WARNERR=no

.include "../../mk/curses.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
