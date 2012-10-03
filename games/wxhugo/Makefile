# $NetBSD: Makefile,v 1.30.2.1 2012/10/03 12:07:50 spz Exp $
#

DISTNAME=	hugov31_unix_source
PKGNAME=	wxhugo-3.1.02
PKGREVISION=	19
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/hugo/source/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTFILE_WX}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.generalcoffee.com/hugo.html
COMMENT=	Interactive fiction interpreter with sound and graphics support

DISTFILE_WX=	hugov31_wxwin_source${EXTRACT_SUFX}
#EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	hugo-3.1.02
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/hugov3.1.02/hewx

# The gcc-2.95 Preprocessor chokes on DOS line-ends in macro continuations
SUBST_CLASSES+=		dos_eol
SUBST_MESSAGE.dos_eol=	Removing DOS line-ends
SUBST_STAGE.dos_eol=	post-extract
SUBST_FILES.dos_eol=	*.c *.cpp */*.c */*.cpp */*/*.c */*/*.cpp
SUBST_FILTER_CMD.dos_eol=	${TR} -d '\r'

INSTALLATION_DIRS=	bin

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hewx ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
