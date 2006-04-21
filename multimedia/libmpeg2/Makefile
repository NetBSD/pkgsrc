# $NetBSD: Makefile,v 1.14 2006/04/21 07:15:38 wulf Exp $

DISTNAME=	mpeg2dec-0.4.0b
PKGNAME=	libmpeg2-0.4.0b
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# remove on next update, only needed for 0.4.0b
WRKSRC=		${WRKDIR}/mpeg2dec-0.4.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=    libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=    libmpeg2/libmpeg2.pc.in

CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
CONFIGURE_ENV+=		LIBMPEG2_CFLAGS=-prefer-non-pic
.  endif
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
