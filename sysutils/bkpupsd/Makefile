# $NetBSD: Makefile,v 1.3 2001/07/29 14:40:26 taca Exp $
#

DISTNAME=	bkpupsd-2.0pl3
PKGNAME=	${DISTNAME:S/pl/./}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jepro.co.jp/pub/jepro/misc/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.jepro.co.jp/
COMMENT=	simple UPS daemon for BK-Pro, BK series and FREQUPS F series

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	DEFAULT_DEVICE=${DEFAULT_SERIAL_DEVICE}

.include "../../mk/bsd.pkg.mk"
