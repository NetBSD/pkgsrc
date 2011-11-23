# $NetBSD: Makefile,v 1.5 2011/11/23 13:09:55 adam Exp $

DISTNAME=	MediaInfo_CLI_0.7.51_GNU_FromSource
PKGNAME=	mediainfo-0.7.51
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediainfo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mediainfo.sourceforge.net/
COMMENT=	Utility to supply technical information about audio and video files
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/MediaInfo_CLI_GNU_FromSource
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

OVERRIDE_DIRDEPTH=	4
INSTALLATION_DIRS=	bin

do-configure:

do-build:
	cd ${WRKSRC} && ./CLI_Compile.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MediaInfo/Project/GNU/CLI/mediainfo \
	    ${DESTDIR}${PREFIX}/bin/mediainfo

.include "../../mk/bsd.pkg.mk"
