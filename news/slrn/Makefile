# $NetBSD: Makefile,v 1.29 2003/10/27 21:48:27 cube Exp $
#

DISTNAME=	slrn-0.9.8.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slrn/}
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://slrn.sourceforge.net/patches/
PATCHFILES=	slrn-0.9.8.0-ranges.diff \
		slrn-0.9.8.0-post.diff
PATCH_DIST_STRIP=      -p1

MAINTAINER=	mjl@NetBSD.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--disable-inews --with-slrnpull --enable-spool \
		--enable-grouplens --with-libdir=${PREFIX}/lib/slrn \
		--enable-mid-cache \
		--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../mk/bsd.prefs.mk"

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
.if ${OPSYS} == "NetBSD" && ${OS_VERSION} == "1.3.2"
CONFIGURE_ENV+=	INSTALL=/usr/bin/install
.endif

.if ${OPSYS} == "Linux"
LDFLAGS+=	-ldl
.endif

.include "../../devel/libslang/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
