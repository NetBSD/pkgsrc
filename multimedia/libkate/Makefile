# $NetBSD: Makefile,v 1.1 2013/05/15 00:41:42 rodent Exp $
#

DISTNAME=	libkate-0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	http://libkate.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.xiph.org/index.php/OggKate
COMMENT=	Overlay codec, originally designed for karaoke and text
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex pkg-config

PKGCONFIG_OVERRIDE+=	misc/pkgconfig/oggkate.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/kate.pc.in

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
