# $NetBSD: Makefile,v 1.2 2012/02/14 23:11:47 gdt Exp $
#

DISTNAME=	libunistring-0.9.3
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.gnu.org/gnu/libunistring/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libunistring/
COMMENT=	Unicode string library
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
