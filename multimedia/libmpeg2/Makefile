# $NetBSD: Makefile,v 1.18 2007/01/10 14:58:24 joerg Exp $

DISTNAME=	mpeg2dec-0.4.1
PKGNAME=	libmpeg2-0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libmpeg2.sourceforge.net/
COMMENT=	Library for decoding mpeg-2 and mpeg-1 video streams

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=	libmpeg2/libmpeg2.pc.in

CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_header_altivec_h=no
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
