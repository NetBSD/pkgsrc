# $NetBSD: Makefile,v 1.18 2001/11/29 01:12:44 hubertf Exp $
#

DISTNAME=	slrn-0.9.7.2
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://slrn.sourceforge.net/pub/slrn/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/ \
		ftp://ftp.fu-berlin.de/pub/unix/news/slrn/ \
		ftp://ftp.ntua.gr/pub/lang/slang/ \
		ftp://ftp.plig.org/pub/slrn/

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader

PATCH_SITES=		http://slrn.sourceforge.net/patches/
PATCHFILES=		slrn-0.9.7.2-decode.diff
PATCH_DIST_STRIP=	-p1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-X --disable-inews --with-slrnpull \
		--disable-gen-mid --with-libdir=${PREFIX}/lib/slrn

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

.include "../../devel/libslang/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
