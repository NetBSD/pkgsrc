# $NetBSD: Makefile,v 1.12 2004/08/23 04:03:34 mrg Exp $
#

DISTNAME=	a52dec-0.7.4
PKGNAME=	${DISTNAME:S/a52dec/liba52/}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://liba52.sourceforge.net/
COMMENT=	Free ATSC A/52 stream decoder library

USE_BUILDLINK3=		yes
GNU_CONFIGURE=  	yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-mlib
CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/bsd.pkg.mk"
