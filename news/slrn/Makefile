# $NetBSD: Makefile,v 1.19 2001/12/01 20:50:05 mjl Exp $
#

DISTNAME=	slrn-0.9.7.3
CATEGORIES=	news
MASTER_SITES=	http://prdownloads.sourceforge.net/slrn/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-X --disable-inews --with-slrnpull \
		--enable-spool --enable-grouplens \
		--disable-gen-mid --with-libdir=${PREFIX}/lib/slrn \

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

.include "../../devel/libslang/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
