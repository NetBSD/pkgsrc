# $NetBSD: Makefile,v 1.69 2004/02/20 19:25:39 jmmv Exp $
#

DISTNAME=		abiword-${DIST_VER}
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.abisource.com/
COMMENT=		Open Source cross-platform word processor

BUILD_USES_MSGFMT=	yes

# GTK1 version and previous name of the GTK2 version
CONFLICTS=		abiword-personal-[0-9]* abiword2-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME}/abi
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		run
USE_X11=		yes

REPLACE_PERL=		user/wp/scripts/abw2html.pl

USE_GNU_ICONV=		yes # XXX

MAKEFILE=		GNUmakefile

DIST_VER=		2.0.3

CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-sys-wv
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-popt=${BUILDLINK_PREFIX.popt}
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=			ABIWORD_USES_GUCHARMAP

.if defined(ABIWORD_USES_GUCHARMAP) && \
    !empty(ABIWORD_USES_GUCHARMAP:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=		--enable-gucharmap
.include "../../fonts/gucharmap/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--disable-gucharmap
.endif

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
