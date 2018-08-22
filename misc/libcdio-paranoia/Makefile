# $NetBSD: Makefile,v 1.7 2018/08/22 09:45:43 wiz Exp $

DISTNAME=	libcdio-paranoia-10.2+0.93+1
PKGNAME=	libcdio-paranoia-0.93
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library: CDDA support
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
PKGCONFIG_OVERRIDE+=	libcdio_cdda.pc.in
PKGCONFIG_OVERRIDE+=	libcdio_paranoia.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs
INFO_FILES=		yes

.include "../../misc/libcdio/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
