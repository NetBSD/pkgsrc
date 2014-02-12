# $NetBSD: Makefile,v 1.66 2014/02/12 23:18:22 tron Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
PKGREVISION=	21
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.org/downloads/${KTORRENT_VER}/
EXTRACT_SUFX=	.tar.bz2

BUILD_DEPENDS+= automoc4>=0.9.87:../../devel/automoc4

.include "../../net/libktorrent/Makefile.version"

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE4
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt pkg-config perl
USE_CMAKE=		yes

DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

CFLAGS+=		-DENABLE_KIO_MAGNET=1
SCRDIR=			share/kde/apps/ktorrent/scripts

CHECK_INTERPRETER_SKIP= ${SCRDIR}/auto_remove/auto_remove.py \
			${SCRDIR}/auto_resume/auto_resume.py \
			${SCRDIR}/email_notifications/email_notifications.py \
			${SCRDIR}/tracker_groups/tracker_groups.py

.include "../../audio/taglib/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../net/libktorrent/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
