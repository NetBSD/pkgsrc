# $NetBSD: Makefile,v 1.62 2003/12/28 23:37:06 jmmv Exp $
#

DISTNAME=		abiword-${DIST_VER}
PKGREVISION=				1
WRKSRC=			${WRKDIR}/${DISTNAME}/abi
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.abisource.com/
COMMENT=		Open Source cross-platform word processor

BUILD_USES_MSGFMT=	yes

# GTK1 version and previous name of the GTK2 version
CONFLICTS=		abiword-personal-[0-9]* abiword2-[0-9]*

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		run
USE_X11=		yes

REPLACE_PERL=		user/wp/scripts/abw2html.pl

USE_GNU_ICONV=		yes # XXX

MAKEFILE=		GNUmakefile

DIST_VER=		2.0.2

CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-sys-wv
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-popt=${BUILDLINK_PREFIX.popt}
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=			ABIWORD_USES_GUCHARMAP

ABIWORD_USES_GUCHARMAP?=	NO

.if !empty(ABIWORD_USES_GUCHARMAP:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=		--enable-gucharmap
.include "../../fonts/gucharmap/buildlink2.mk"
.else
CONFIGURE_ARGS+=		--disable-gucharmap
.endif

.include "../../converters/fribidi/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../converters/wv/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../textproc/enchant/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
