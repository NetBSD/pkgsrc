# $NetBSD: Makefile,v 1.6 2024/09/15 13:09:51 wiz Exp $

DISTNAME=	libffcall-2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libffcall/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libffcall/
COMMENT=	Foreign function call libraries
LICENSE=	gnu-gpl-v2

# make: make: don't know how to make avcall/avcall.lo. Stop
# https://savannah.gnu.org/bugs/index.php?66220
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared

MAKE_FLAGS+=		htmldir=${PREFIX}/share/doc/ffcall

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
