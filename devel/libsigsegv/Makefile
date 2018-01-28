# $NetBSD: Makefile,v 1.16 2018/01/28 15:59:40 wiz Exp $

DISTNAME=		libsigsegv-2.12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://savannah.gnu.org/projects/libsigsegv/
COMMENT=		Library for handling page faults in user mode
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
