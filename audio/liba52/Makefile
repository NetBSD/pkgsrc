# $NetBSD: Makefile,v 1.2 2001/12/11 04:01:34 wiz Exp $
#

DISTNAME=	a52dec-0.7.1b
PKGNAME=	${DISTNAME:S/a52dec/liba52/:S/1b/1.2/}
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
