# $NetBSD: Makefile,v 1.3 2001/10/06 12:43:08 rh Exp $
#

DISTNAME=		libunicode-0.4
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/libunicode/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		library for manipulating Unicode characters and strings

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
