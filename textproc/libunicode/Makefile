# $NetBSD: Makefile,v 1.4 2002/08/25 18:40:08 jlam Exp $
#

DISTNAME=		libunicode-0.4
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/libunicode/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		library for manipulating Unicode characters and strings

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
