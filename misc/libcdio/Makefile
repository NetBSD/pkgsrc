# $NetBSD: Makefile,v 1.37 2008/11/10 22:30:43 wiz Exp $

DISTNAME=	libcdio-0.81
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run pkg-config
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	libcdio.pc.in
PKGCONFIG_OVERRIDE+=	libcdio++.pc.in
PKGCONFIG_OVERRIDE+=	libcdio_cdda.pc.in
PKGCONFIG_OVERRIDE+=	libcdio_paranoia.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660++.pc.in
PKGCONFIG_OVERRIDE+=	libudf.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs
CONFIGURE_ARGS+=	--enable-cpp-progs
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# XXX we just replace the freebsd module so save patches
pre-patch:
	${CP} ${FILESDIR}/_cdio_netbsd.c ${WRKSRC}/lib/driver/FreeBSD/freebsd.c
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
