# $NetBSD: Makefile,v 1.17 2018/11/12 03:52:38 ryoon Exp $
#

DISTNAME=	libkate-0.4.1
PKGREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	http://libkate.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.xiph.org/index.php/OggKate
COMMENT=	Overlay codec, originally designed for karaoke and text
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex pkg-config

CONFIGURE_ENV+=		ac_cv_lib_lex="none needed"

PKGCONFIG_OVERRIDE+=	misc/pkgconfig/oggkate.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/kate.pc.in

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
