# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:32 wiz Exp $
#

DISTNAME=	libunicode-0.4
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/libunicode/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.pango.org/
COMMENT=	library for manipulating Unicode characters and strings

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
