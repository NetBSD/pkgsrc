# $NetBSD: Makefile,v 1.3 2002/06/16 18:08:05 wiz Exp $
#

DISTNAME=	a52dec-0.7.3
PKGNAME=	${DISTNAME:S/a52dec/liba52/}
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://liba52.sourceforge.net/
COMMENT=	free ATSC A/52 stream decoder library

GNU_CONFIGURE=  	yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/autotools/ltconfig

CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-mlib
CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.pkg.mk"
