# $NetBSD: Makefile,v 1.5 2013/07/21 10:31:26 shattered Exp $
#

DISTNAME=	libunistring-0.9.3
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.gnu.org/gnu/libunistring/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libunistring/
COMMENT=	Unicode string library
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
