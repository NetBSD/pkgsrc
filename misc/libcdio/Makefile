# $NetBSD: Makefile,v 1.56 2018/08/22 09:45:43 wiz Exp $

DISTNAME=	libcdio-0.93
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
PKGCONFIG_OVERRIDE+=	libcdio.pc.in
PKGCONFIG_OVERRIDE+=	libcdio++.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660++.pc.in
PKGCONFIG_OVERRIDE+=	libudf.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs
INFO_FILES=		yes

.include "../../audio/libcddb/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
