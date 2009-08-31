# $NetBSD: Makefile,v 1.4 2009/08/31 20:17:48 wiz Exp $
#

DISTNAME=	fbreader-sources-0.10.1
PKGNAME=	${DISTNAME:S/-sources//}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.fbreader.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fbreader.org/
COMMENT=	Ebook reader software

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
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
