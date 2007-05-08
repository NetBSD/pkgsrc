# $NetBSD: Makefile,v 1.2 2007/05/08 15:47:48 joerg Exp $
#

DISTNAME=	dbus-qt3-0.70
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbus.freedesktop.org/
COMMENT=	D-BUS Qt bindings

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-qt3-moc=${QTDIR}/bin/moc
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
