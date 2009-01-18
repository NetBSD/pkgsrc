# $NetBSD: Makefile,v 1.1.1.1 2009/01/18 17:39:37 wiz Exp $
#

DISTNAME=	fbreader-sources-0.10.1
PKGNAME=	${DISTNAME:S/-sources//}
CATEGORIES=	misc
MASTER_SITES=	http://www.fbreader.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fbreader.org/
COMMENT=	Ebook reader software

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_ENV+=	INSTALLDIR=${PREFIX}
MAKE_ENV+=	DESTDIR=${DESTDIR}
MAKE_ENV+=	LDFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_ENV+=	TARGET_ARCH=desktop

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/liblinebreak/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
