# $NetBSD: Makefile,v 1.79 2004/10/03 00:14:37 tv Exp $
#

DISTNAME=		abiword-2.0.5
PKGREVISION=	1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.abisource.com/
COMMENT=		Open Source cross-platform word processor

BUILD_USES_MSGFMT=	yes

# GTK1 version and previous name of the GTK2 version
CONFLICTS=		abiword-personal-[0-9]* abiword2-[0-9]*

MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_PERL5=		run
USE_X11=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/abi

USE_BUILTIN.iconv=	no # Make sure we get libiconv dependency.

REPLACE_PERL=		user/wp/scripts/abw2html.pl

CONFIGURE_ARGS+=	--enable-gucharmap
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-sys-wv
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-popt=${BUILDLINK_PREFIX.popt}
CONFIGURE_ARGS+=	--with-libjpeg-prefix=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
