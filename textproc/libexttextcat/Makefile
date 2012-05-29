# $NetBSD: Makefile,v 1.2 2012/05/29 15:34:37 wiz Exp $

DISTNAME=	libexttextcat-3.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://cgit.freedesktop.org/libreoffice/libexttextcat/
COMMENT=	Text categorization library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	libtextcat-[0-9]*

PKGCONFIG_OVERRIDE=	libexttextcat.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
