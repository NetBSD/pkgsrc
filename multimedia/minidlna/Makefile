# $NetBSD: Makefile,v 1.26 2017/09/18 09:53:28 maya Exp $

DISTNAME=	minidlna-1.1.5
PKGREVISION=	8
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

INSTALLATION_DIRS=	share/examples/minidlna ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

pre-install:
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/minidlnad.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
