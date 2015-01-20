# $NetBSD: Makefile,v 1.12 2015/01/20 09:59:33 degroote Exp $

DISTNAME=	minidlna-1.1.4
PKGREVISION= 	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minidlna/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minidlna.sourceforge.net/
COMMENT=	DLNA server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=      yes
EGDIR=		${PREFIX}/share/examples/minidlna
USE_TOOLS+=     msgfmt

CONF_FILES=	${EGDIR}/minidlna.conf \
		${PKG_SYSCONFDIR}/minidlna.conf
RCD_SCRIPTS=	minidlna

INSTALLATION_DIRS=	share/examples/minidlna

pre-install:
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${DESTDIR}${EGDIR}

.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
