# $NetBSD: Makefile,v 1.18 2003/07/13 13:53:18 wiz Exp $
#

DISTNAME=	kdf-0.5.1
PKGREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.edu.uni-klu.ac.at/~mkropfbe
COMMENT=	Shows disk usage graphically and lets you mount/umount devices

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=--datadir=${BUILDLINK_PREFIX.kdebase}/share/kde \
		--with-qt-dir=${QTDIR} \
		--enable-path-check
CONFIGURE_ENV=	KDEDIR=${BUILDLINK_PREFIX.kdebase} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/kdebase/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
