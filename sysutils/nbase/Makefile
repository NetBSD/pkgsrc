# $NetBSD: Makefile,v 1.8 2023/06/06 12:42:21 riastradh Exp $
#

DISTNAME=	nbase-7.0.0.7
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

.include "../../devel/mk-configure/mk-c.mk"

MAKE_FLAGS+=	PREFIX=${PREFIX}/nbase \
		MANDIR=${PREFIX}/nbase/${PKGMANDIR} \
		LINKSPREFIX=${PREFIX}

# -Wno-error=unused-result -Werror=strict-aliasing(libnbcompat,)
MAKE_FLAGS+=	WARNERR=no

.include "../../mk/curses.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
