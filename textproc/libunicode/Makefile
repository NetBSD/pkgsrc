# $NetBSD: Makefile,v 1.11 2006/02/26 13:51:16 schwarz Exp $
#

DISTNAME=		libunicode-0.4
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libunicode/0.4/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for manipulating Unicode characters and strings

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
