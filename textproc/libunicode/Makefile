# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:20 tv Exp $
#

DISTNAME=		libunicode-0.4
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libunicode/0.4/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for manipulating Unicode characters and strings

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
