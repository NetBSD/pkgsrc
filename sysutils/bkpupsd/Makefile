# $NetBSD: Makefile,v 1.2 2001/05/07 03:28:11 dmcmahill Exp $
#

DISTNAME=	bkpupsd-2.0pl3
PKGNAME=	${DISTNAME:S/pl/./}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jepro.co.jp/pub/jepro/misc/

MAINTAINER=	taca@kyoto.jepro.co.jp
HOMEPAGE=	http://www.jepro.co.jp/
COMMENT=	simple UPS daemon for BK-Pro, BK series and FREQUPS F series

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	DEFAULT_DEVICE=${DEFAULT_SERIAL_DEVICE}

.include "../../mk/bsd.pkg.mk"
