# $NetBSD: Makefile,v 1.5 2002/10/19 10:54:58 rh Exp $
#

DISTNAME=		libunicode-0.4
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libunicode/0.4/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		library for manipulating Unicode characters and strings

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
