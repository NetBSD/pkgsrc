# $NetBSD: Makefile,v 1.6 2003/06/02 01:21:37 jschauma Exp $
#

DISTNAME=	a52dec-0.7.4
PKGNAME=	${DISTNAME:S/a52dec/liba52/}
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://liba52.sourceforge.net/
COMMENT=	free ATSC A/52 stream decoder library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=  	yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/autotools/ltconfig

CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-mlib
CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.pkg.mk"
