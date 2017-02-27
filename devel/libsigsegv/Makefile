# $NetBSD: Makefile,v 1.15 2017/02/27 09:52:47 wiz Exp $

DISTNAME=		libsigsegv-2.11
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
