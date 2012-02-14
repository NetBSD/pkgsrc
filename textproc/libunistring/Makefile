# $NetBSD: Makefile,v 1.1.1.1 2012/02/14 23:06:50 gdt Exp $
#

DISTNAME=	libunistring-0.9.3
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.gnu.org/gnu/libunistring/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://ftp.gnu.org/gnu/libunistring/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
