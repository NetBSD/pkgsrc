# $NetBSD: Makefile,v 1.36 2019/07/01 04:08:32 ryoon Exp $

DISTNAME=		bibletime-2.10.1
PKGREVISION=		37
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bibletime/}
EXTRACT_SUFX=		.tar.xz
EXTRACT_USING=		bsdtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bibletime.info/
COMMENT=		Bible study program based on SWORD and QT
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		docdir
SUBST_FILES.docdir=	${WRKSRC}/cmake/BTDocumentation.cmake
SUBST_FILES.docdir+=	${WRKSRC}/src/util/directory.cpp
SUBST_STAGE.docdir=	pre-configure
SUBST_SED.docdir=	-e 's,bibletime/docs,doc/bibletime,g'

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

.include "options.mk"

.include "../../misc/sword/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
