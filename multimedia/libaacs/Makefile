# $NetBSD: Makefile,v 1.1 2014/01/08 23:04:43 wiz Exp $

DISTNAME=	libaacs-0.7.0
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/libaacs/0.7.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/libaacs.html
COMMENT=	Advanced Access Content System specification implementation
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison pkg-config

PKGCONFIG_OVERRIDE+=	src/libaacs.pc.in

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
