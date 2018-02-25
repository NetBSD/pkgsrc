# $NetBSD: Makefile,v 1.2 2018/02/25 21:08:53 wiz Exp $

DISTNAME=	libffcall-2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libffcall/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libffcall/
COMMENT=	Foreign function call libraries
LICENSE=	gnu-gpl-v2

# make: make: don't know how to make avcall/avcall.lo. Stop
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared

MAKE_FLAGS+=		htmldir=${PREFIX}/share/doc/ffcall

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
