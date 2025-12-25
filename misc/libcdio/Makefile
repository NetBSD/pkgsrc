# $NetBSD: Makefile,v 1.69 2025/12/25 18:00:39 gdt Exp $

DISTNAME=	libcdio-2.1.0
PKGREVISION=	5
CATEGORIES=	misc
# As of 2.2.0, upstream no longer provides releases at MASTER_SITE_GNU.
# Thus this package needs Github Kool-Aid Accomodation.
# Now https://github.com/libcdio/libcdio/releases/download/2.2.0/libcdio-2.2.0.tar.bz2
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs
INFO_FILES=		yes
PKGCONFIG_OVERRIDE+=	libcdio.pc.in
PKGCONFIG_OVERRIDE+=	libcdio++.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660++.pc.in
PKGCONFIG_OVERRIDE+=	libudf.pc.in
TEST_TARGET=		check

# fix linking of cdda_player
MAKE_FLAGS.NetBSD+=	CURTERMLIB=-lterminfo

.include "../../audio/libcddb/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
