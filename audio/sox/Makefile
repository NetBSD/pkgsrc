# $NetBSD: Makefile,v 1.33 2005/06/24 20:50:31 wiz Exp $

DISTNAME=	sox-12.17.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/} \
		http://www.cnpbagwell.com/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fast-ulaw
CONFIGURE_ARGS+=	--enable-fast-alaw
CONFIGURE_ARGS+=	--disable-oss-dsp
CONFIGURE_ARGS+=	--with-ogg-vorbislib=${BUILDLINK_PREFIX.libvorbis}/lib
CONFIGURE_ARGS+=	--with-ogg-vorbisinc=${BUILDLINK_PREFIX.libvorbis}/include

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		${PKGDIR}/PLIST.common

.if ${OPSYS} != "Interix"
CONFIGURE_ARGS+=	--with-sun-audio
PLIST_SRC+=		${PKGDIR}/PLIST.play
.endif

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
