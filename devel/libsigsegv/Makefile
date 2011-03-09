# $NetBSD: Makefile,v 1.12 2011/03/09 19:41:54 asau Exp $
#

DISTNAME=		libsigsegv-2.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libsigsegv/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://savannah.gnu.org/projects/libsigsegv/
COMMENT=		Library for handling page faults in user mode

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS+=		libsigsegv25-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
