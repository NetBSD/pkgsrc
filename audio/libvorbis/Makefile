# $NetBSD: Makefile,v 1.54 2012/03/05 13:15:06 wiz Exp $

DISTNAME=	libvorbis-1.3.3
CATEGORIES=	devel audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xiph.org/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	vorbis.pc.in
PKGCONFIG_OVERRIDE+=	vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	vorbisfile.pc.in

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
