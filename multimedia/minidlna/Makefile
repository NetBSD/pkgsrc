# $NetBSD: Makefile,v 1.3 2013/01/26 21:38:26 adam Exp $
#

DISTNAME=	minidlna_1.0.25_src
PKGNAME=	minidlna-1.0.25
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minidlna/1.0.25/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minidlna.sourceforge.net/
COMMENT=	DLNA server
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/minidlna-1.0.25
MAKE_FILE=	BSDmakefile
EGDIR=		${PREFIX}/share/examples/minidlna

SUBST_CLASSES+=	confdir
SUBST_STAGE.confdir= pre-build
SUBST_FILES.confdir= minidlna.c
SUBST_VARS.confdir= PKG_SYSCONFDIR

CONF_FILES=	${EGDIR}/minidlna.conf \
		${PKG_SYSCONFDIR}/minidlna.conf
RCD_SCRIPTS=	minidlna

INSTALLATION_DIRS=	sbin share/examples/minidlna

post-patch:
	${CP} \
	${FILESDIR}/BSDmakefile \
	${FILESDIR}/config.h \
	${FILESDIR}/getifaddr.c \
	${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minidlna ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${DESTDIR}${EGDIR}

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
