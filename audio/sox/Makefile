# $NetBSD: Makefile,v 1.39 2006/09/03 00:26:20 ben Exp $

DISTNAME=	sox-12.18.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sox/} \
		http://www.cnpbagwell.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sox.sourceforge.net/
COMMENT=	SOund eXchange - universal sound sample translator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fast-ulaw
CONFIGURE_ARGS+=	--enable-fast-alaw
.if ${OPSYS} != "DragonFly" && ${OPSYS} != "FreeBSD"
CONFIGURE_ARGS+=	--disable-oss-dsp
.endif
CONFIGURE_ARGS+=	--with-ogg-vorbislib=${BUILDLINK_PREFIX.libvorbis}/lib
CONFIGURE_ARGS+=	--with-ogg-vorbisinc=${BUILDLINK_PREFIX.libvorbis}/include

PLIST_SRC=		${PKGDIR}/PLIST.common

.if ${OPSYS} != "Interix" && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--with-sun-audio
PLIST_SRC+=		${PKGDIR}/PLIST.play
.endif

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
