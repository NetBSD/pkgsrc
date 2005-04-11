# $NetBSD: Makefile,v 1.14 2005/04/11 21:44:53 tv Exp $
#

DISTNAME=	a52dec-0.7.4
PKGNAME=	${DISTNAME:S/a52dec/liba52/}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://liba52.sourceforge.net/
COMMENT=	Free ATSC A/52 stream decoder library

GNU_CONFIGURE=  	yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-mlib
CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.pkg.mk"
