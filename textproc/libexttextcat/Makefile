# $NetBSD: Makefile,v 1.7 2014/07/22 12:26:39 wiz Exp $

DISTNAME=	libexttextcat-3.4.4
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://cgit.freedesktop.org/libreoffice/libexttextcat/
COMMENT=	Text categorization library
LICENSE=	modified-bsd

CONFLICTS+=	libtextcat-[0-9]*

PKGCONFIG_OVERRIDE=	libexttextcat.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
