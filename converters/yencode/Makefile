# $NetBSD: Makefile,v 1.15 2012/10/03 00:20:19 asau Exp $
#

DISTNAME=	yencode-0.46
PKGNAME=	yencode-0.4.6
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yencode/}

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://www.yencode.org/
COMMENT=	yenc format encoder and decoder

GNU_CONFIGURE=		YES

CFLAGS.SunOS+=	-Du_int64_t=uint64_t
LIBS.SunOS+=	-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
