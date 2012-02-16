# $NetBSD: Makefile,v 1.14 2012/02/16 18:08:49 hans Exp $
#

DISTNAME=	yencode-0.46
PKGNAME=	yencode-0.4.6
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yencode/}

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://www.yencode.org/
COMMENT=	yenc format encoder and decoder

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

CFLAGS.SunOS+=	-Du_int64_t=uint64_t
LIBS.SunOS+=	-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
