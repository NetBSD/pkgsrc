# $NetBSD: Makefile,v 1.21 2026/04/09 06:00:42 wiz Exp $

DISTNAME=	libunistring-1.4.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=libunistring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libunistring/
COMMENT=	Unicode string library
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 # or-later in both cases

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes
TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
