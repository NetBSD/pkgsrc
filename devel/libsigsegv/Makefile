# $NetBSD: Makefile,v 1.18 2021/01/25 10:01:14 wiz Exp $

DISTNAME=		libsigsegv-2.13
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		https://savannah.gnu.org/projects/libsigsegv/
COMMENT=		Library for handling page faults in user mode
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
