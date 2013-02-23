# $NetBSD: Makefile,v 1.8 2013/02/23 02:33:46 schmonz Exp $

DISTNAME=	MediaInfo_CLI_0.7.62_GNU_FromSource
PKGNAME=	mediainfo-0.7.62
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediainfo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mediainfo.sourceforge.net/
COMMENT=	Utility to supply technical information about audio and video files
LICENSE=	gnu-lgpl-v3

WRKSRC=			${WRKDIR}/MediaInfo_CLI_GNU_FromSource
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

OVERRIDE_DIRDEPTH=	4
INSTALLATION_DIRS=	bin

do-configure:

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./CLI_Compile.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MediaInfo/Project/GNU/CLI/mediainfo \
	    ${DESTDIR}${PREFIX}/bin/mediainfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
