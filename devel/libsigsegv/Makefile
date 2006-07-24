# $NetBSD: Makefile,v 1.3 2006/07/24 13:39:26 joerg Exp $
#

DISTNAME=		libsigsegv-2.4
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://libsigsegv.sourceforge.net/
COMMENT=		Library for handling page faults in user mode

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
