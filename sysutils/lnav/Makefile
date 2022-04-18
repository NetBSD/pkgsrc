# $NetBSD: Makefile,v 1.20 2022/04/18 19:12:06 adam Exp $

DISTNAME=	lnav-0.7.3
PKGREVISION=	18
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tstack/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lnav.org/
COMMENT=	Log file navigator, an enhanced log viewer
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
