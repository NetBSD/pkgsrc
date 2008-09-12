# $NetBSD: Makefile,v 1.8 2008/09/12 22:14:11 ahoka Exp $
#

DISTNAME=		libsigsegv-2.6
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
