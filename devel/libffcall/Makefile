# $NetBSD: Makefile,v 1.3 2019/10/10 11:53:12 wiz Exp $

DISTNAME=	libffcall-2.2
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
