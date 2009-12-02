# $NetBSD: Makefile,v 1.49 2009/12/02 12:41:25 wiz Exp $

DISTNAME=	libvorbis-1.2.3
PKGREVISION=	1
CATEGORIES=	devel audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.xiph.org/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	vorbis.pc.in
PKGCONFIG_OVERRIDE+=	vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	vorbisfile.pc.in

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
