# $NetBSD: Makefile,v 1.22 2002/10/09 14:00:57 wiz Exp $
#

DISTNAME=	slrn-0.9.7.4
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slrn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-X --disable-inews --with-slrnpull \
		--enable-spool --enable-grouplens \
		--with-gen-mid --with-libdir=${PREFIX}/lib/slrn \
		--enable-mid-cache

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

.include "../../devel/libslang/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
