# $NetBSD: Makefile,v 1.68 2020/06/02 08:24:23 adam Exp $

DISTNAME=		dvdauthor-0.7.2
PKGREVISION=		26
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdauthor/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dvdauthor.sourceforge.net/
COMMENT=		Tools to assist DVD authoring
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/dvdauthor

GNU_CONFIGURE=		YES
USE_TOOLS+=		flex gmake yacc pkg-config
# To keep a consistent behavior with previous releases
CONFIGURE_ARGS+=	--enable-default-video-format=ntsc

SUBST_CLASSES+=		freetype
SUBST_STAGE.freetype=	post-patch
SUBST_FILES.freetype=	configure
SUBST_MESSAGE.freetype=	Dont use obsolete freetype-config
SUBST_SED.freetype=	-e "s,freetype-config,pkg-config freetype2,"

.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
