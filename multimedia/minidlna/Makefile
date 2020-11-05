# $NetBSD: Makefile,v 1.43 2020/11/05 09:08:48 ryoon Exp $

PKGNAME=	minidlna-1.2.1.20180601
PKGREVISION=	9
DISTNAME=	minidlna-git-799e6cf505ec470b2bf0ae4118143380aa16b837
CATEGORIES=	multimedia
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=minidlna/}
MASTER_SITES=	https://sourceforge.net/code-snapshots/git/m/mi/minidlna/git.git/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minidlna.sourceforge.net/
COMMENT=	DLNA server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
EGDIR=		${PREFIX}/share/examples/minidlna
USE_TOOLS+=	msgfmt autoreconf autoconf automake

CONF_FILES=	${EGDIR}/minidlna.conf \
		${PKG_SYSCONFDIR}/minidlna.conf
RCD_SCRIPTS=	minidlna

INSTALLATION_DIRS=	share/examples/minidlna ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

pre-install:
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/minidlnad.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8


BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
