# $NetBSD: Makefile,v 1.10 2009/12/15 17:53:43 asau Exp $
#

DISTNAME=		libsigsegv-2.8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://libsigsegv.sourceforge.net/
COMMENT=		Library for handling page faults in user mode

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS+=		libsigsegv25-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
