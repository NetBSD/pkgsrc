# $NetBSD: Makefile,v 1.46 2010/06/13 22:45:13 wiz Exp $

DISTNAME=	slrn-0.9.9p1
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-inews --with-slrnpull --enable-spool \
			--enable-grouplens --with-libdir=${PREFIX}/lib/slrn \
			--enable-mid-cache \
			--with-slang=${PREFIX} \
			--with-slanglib=-lslang2 \
			--with-slanginc=slang2/slang.h \
			--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../mk/bsd.prefs.mk"

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
.if ${OPSYS} == "NetBSD" && ${OS_VERSION} == "1.3.2"
CONFIGURE_ENV+=		INSTALL=/usr/bin/install
.endif

LDFLAGS.Linux+=	-ldl

.include "../../devel/libslang2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
