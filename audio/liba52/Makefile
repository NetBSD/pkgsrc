# $NetBSD: Makefile,v 1.1.1.1 2001/12/10 19:49:46 veego Exp $
#

DISTNAME=	a52dec-0.7.1b
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
