# $NetBSD: Makefile,v 1.26 2003/04/27 14:37:02 cjep Exp $
#

DISTNAME=	slrn-0.9.7.4
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slrn/}
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://slrn.sourceforge.net/patches/
PATCHFILES=	slrn-0.9.7.4-po.diff \
		slrn-0.9.7.4-popup_win.diff \
		slrn-0.9.7.4-mem_leak.diff \
		slrn-0.9.7.4-link_subjects.diff \
		slrn-0.9.7.4-strcasecmp.diff
PATCH_DIST_STRIP=      -p1

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--without-X --disable-inews --with-slrnpull \
		--enable-spool --enable-grouplens \
		--with-gen-mid --with-libdir=${PREFIX}/lib/slrn \
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
