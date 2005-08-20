# $NetBSD: Makefile,v 1.14.2.1 2005/08/20 14:36:15 salo Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
CONFIGURE_ENV+=		LIBA52_CFLAGS=-prefer-non-pic
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
