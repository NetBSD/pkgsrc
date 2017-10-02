# $NetBSD: Makefile,v 1.10 2017/10/02 15:20:38 wiz Exp $

DISTNAME=	libexttextcat-3.4.5
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	https://cgit.freedesktop.org/libreoffice/libexttextcat/
COMMENT=	Text categorization library
LICENSE=	modified-bsd

CONFLICTS+=	libtextcat-[0-9]*

PKGCONFIG_OVERRIDE=	libexttextcat.pc.in

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
