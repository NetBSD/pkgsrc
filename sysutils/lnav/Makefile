# $NetBSD: Makefile,v 1.34 2024/05/29 16:34:28 adam Exp $

DISTNAME=	lnav-0.11.1
PKGREVISION=	8
CATEGORIES=	sysutils textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tstack/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lnav.org/
COMMENT=	Log file navigator, an enhanced log viewer
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:build gmake

# Force it -- configure thinks it can build with c++14
# but the program uses alloca() so depends on the gnu feature set
FORCE_CXX_STD=	gnu++14

GCC_REQD+=	8

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
