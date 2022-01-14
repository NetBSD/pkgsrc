# $NetBSD: Makefile,v 1.15 2022/01/14 01:10:22 gdt Exp $

DISTNAME=	libunistring-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.gnu.org/gnu/libunistring/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libunistring/
COMMENT=	Unicode string library
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes
TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
