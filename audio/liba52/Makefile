# $NetBSD: Makefile,v 1.8 2003/07/21 16:30:41 martti Exp $
#

DISTNAME=	a52dec-0.7.4
PKGNAME=	${DISTNAME:S/a52dec/liba52/}
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://liba52.sourceforge.net/
COMMENT=	Free ATSC A/52 stream decoder library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=  	yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/autotools/ltconfig

CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-mlib
CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.pkg.mk"
